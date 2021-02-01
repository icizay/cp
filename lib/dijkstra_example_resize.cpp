#include <bits/stdc++.h>
using namespace std;

// no negative weight
// adj[u, v, w]
const int64_t INF = 1e12;
vector<vector<array<int64_t, 2>>> adj;
vector<int64_t> dist;
vector<bool> processed;

vector<int> p; // path

void exp_path(vector<int> &path, int s, int e){
    for(int v = e; v != s; v = p[v])
	path.emplace_back(v);
    path.emplace_back(s);

    reverse(path.begin(), path.end());
}

void solve(){
    int n, m; cin >> n >> m;
    int s = 0, e = n - 1;
    dist.resize(n, INF);
    processed.resize(n, false);
    adj.resize(n);
    p.resize(n);

    for(int i = 0; i < m; ++i){
	int64_t u, v, w; cin >> u >> v >> w;
	--u, --v;
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    priority_queue<array<int64_t, 2>> q;
    dist[s] = 0;
    q.push({0,s});
    while(!q.empty()){
	int a = q.top()[1]; q.pop();
	if(processed[a]) continue;
	processed[a] = true;
	for(auto [b,w] : adj[a]){
	    if(dist[a]+w < dist[b]){
		dist[b] = dist[a] + w;
		p[b] = a; // path
		q.push({-dist[b], b});
	    }
	}
    }

    if(!processed[e]){
	cout << -1 << "\n";
	return;
    }

    vector<int> path;
    exp_path(path, s, e);

    //cout << dist[e] << "\n";

    for(auto i : path) cout << i + 1 << " ";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

