#include <bits/stdc++.h>
using namespace std;

// not really sure ig

int n;
vector<int> parent;
vector<int> vis;
vector<vector<int>> adj;

// -1 = unvisited
// 0 = explored
// 1 = visited

void cycle(int u){
    vis[u] = 0;
    for(auto &v : adj[u]){
	if(vis[v] == -1){ // part of dfs spanning tree
	    cout << u << " " << v << "is tree edge" << "\n";
	    parent[v] = u;
	    cycle(v); 
	}else if(vis[v] == 0){ // cycle 
	    cout << u << " " << v << "is ";
	    if(parent[u] == v) cout << "trivial cycle" << "\n";// trivial cycle / aka bidirectional edge
	    else cout << "back edge" << "\n";// back edge / aka non-trivial cycle
	}else if(vis[v] == 1){
	    cout << u << " " << v << "is ";
	    cout << "cross edge" << "\n"; // forward/cross edge
	}
    }
    vis[u] = 1;
}

// adj.resize(n);
// parent.resize(n, -1);
// vis.resize(n, -1);

void solve(){
    int m; cin >> n >> m;
    adj.resize(n);
    parent.resize(n, -1);
    vis.resize(n, -1);
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	adj[u].push_back(v);
	//adj[v].push_back(u); // undirected
    }
    for(int i = 0; i < n; ++i)
	if(vis[i] == -1) 
	    cycle(i);
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

