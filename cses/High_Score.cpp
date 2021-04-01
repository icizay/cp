#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<array<int64_t, 2>>> adj;
const int64_t INF = LLONG_MAX;
vector<int64_t> dist;
vector<int64_t> cnt;
vector<int64_t> in_queue;
queue<int64_t> q;

bool ford(int node){
    dist[node] = 0; // start from node
    q.push(node);
    in_queue[node] = 1;
    while(!q.empty()){
	int u = q.front();
	q.pop();
	in_queue[u] = 0;
	for(auto [v, w] : adj[u]){
	    if(dist[u] + w < dist[v]){
		dist[v] = dist[u] + w;
		if(!in_queue[v]){
		    q.push(v);
		    in_queue[v] = 1;
		    cnt[v]++;

		    if(cnt[v] > n) return false;
		}
	    }
	}
    }
    return true;
}


// returns true if there is no negative cycle, false else.

// adj.resize(n);
// dist.resize(n, INF);
// in_queue.resize(n, false);
// cnt.resize(n, 0);
// directed graph


// Idea: inverting weights will make bigger edges lower weighted, then if you re-invert at the end it will be your answer


void solve(){
    int m; cin >> n >> m;
    adj.resize(n);
    dist.resize(n, INF);
    in_queue.resize(n, false);
    cnt.resize(n, 0);
    for(int i = 0; i < m; ++i){
	int64_t w;
	int u, v; cin >> u >> v >> w;
	--u, --v;
	adj[u].push_back({v, -w});
    }

    if(ford(0)) cout << -dist[n-1] << "\n";
    else if(dist[n-1] == -1) cout << 1 << "\n";
    else cout << -1 << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

