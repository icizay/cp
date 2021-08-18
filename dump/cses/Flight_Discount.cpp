#include <bits/stdc++.h>
using namespace std;

// no negative weight
// adj[u, v, w]
const int64_t INF = 1e18;
vector<vector<array<int64_t, 2>>> adj, adj2;
vector<array<int64_t, 3>> edges;
vector<int64_t> A, B;
vector<bool> processed;

// idea: for each edge{u, v, w}, find the minimum distance to 0 -> v (if exists), 
// also find the minimum distance to v -> n - 1 (if exists),
// then we can reduce the weight of the edge

// simply, doing 2 dijkstras one with initial and one with inverted graph will work!

void solve(){
    int n, m; cin >> n >> m;
    A.resize(n, INF);
    B.resize(n, INF);
    processed.resize(n, false);
    adj.resize(n);
    adj2.resize(n);
    
    for(int i = 0; i < m; ++i){
	int u, v, w; cin >> u >> v >> w;
	--u, --v;
	adj[u].push_back({v, w});
	adj2[v].push_back({u, w});
	edges.push_back({u, v, w});
    }

    priority_queue<array<int64_t, 2>> q;
    int s = 0; // starting node
    A[s] = 0;
    q.push({0,s});
    while(!q.empty()){
	int a = q.top()[1]; q.pop();
	if(processed[a]) continue;
	processed[a] = true;
	for(auto [b,w] : adj[a]){
	    if(A[a]+w < A[b]){
		A[b] = A[a] + w;
		q.push({-A[b], b});
	    }
	}
    }

    processed.assign(n, false);
    s = n - 1; // starting node
    B[s] = 0;
    q.push({0,s});
    while(!q.empty()){
	int a = q.top()[1]; q.pop();
	if(processed[a]) continue;
	processed[a] = true;
	for(auto [b,w] : adj2[a]){
	    if(B[a]+w < B[b]){
		B[b] = B[a] + w;
		q.push({-B[b], b});
	    }
	}
    }

    int64_t ans = INF;

    for(auto &[u, v, w] : edges){
	if(A[u] != INF && B[v] != INF)
	    ans = min(ans, A[u] + w / 2 + B[v]); 
    }

    cout << ans << "\n";

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
