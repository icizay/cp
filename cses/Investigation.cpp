#include <bits/stdc++.h>
using namespace std;

int n, m;
const int64_t INF = 1e18;
const int64_t MOD = 1e9 + 7;
vector<vector<array<int64_t, 2>>> adj;
vector<int64_t> dist, route, mnn, mxx;
vector<bool> processed;

void solve(){
    cin >> n >> m;
    dist.resize(n, INF);
    processed.resize(n, false);
    adj.resize(n);
    route.resize(n, 0);
    mnn.resize(n, 0);
    mxx.resize(n, 0);

    for(int i = 0; i < m; ++i){
	int u, v, w; cin >> u >> v >> w;
	--u, --v;
	adj[u].push_back({v, w});
    }

    priority_queue<array<int64_t, 2>> q;
    int s = 0;// starting node
    dist[s] = 0;
    route[s] = 1;
    q.push({0,s});
    while(!q.empty()){
	int a = q.top()[1]; q.pop();
	if(processed[a]) continue;
	processed[a] = true;
	for(auto [b,w] : adj[a]){
	    if(dist[a] + w == dist[b]){
		route[b] = (route[b] + route[a]) % MOD;
		mnn[b] = min(mnn[a] + 1, mnn[b]);
		mxx[b] = max(mxx[a] + 1, mxx[b]);
	    }else if(dist[a]+w < dist[b]){
		dist[b] = dist[a] + w;
		route[b] = route[a];
		mnn[b] = mnn[a]+1;
		mxx[b] = mxx[a] + 1;
		q.push({-dist[b], b});
	    }else{
		continue;
	    }
	}
    }

    cout << dist[n-1] << " " << route[n-1] << " " << mnn[n - 1] << " " << mxx[n-1] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

