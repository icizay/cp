#include <bits/stdc++.h>
using namespace std;

int n;
vector<int64_t> parent;
vector<int64_t> vis;
vector<vector<int64_t>> adj;

// -1 = unvisited
// 0 = explored
// 1 = visited
vector<int64_t> ans;
bool flag = false;

void cycle(int64_t u){
    vis[u] = 0;
    for(auto &v : adj[u]){
	if(vis[v] == -1){ // part of dfs spanning tree
	    parent[v] = u;
	    cycle(v); 
	}else if(vis[v] == 0){ // cycle 
	    if(parent[u] == v){
		cout << 3 << "\n";
		cout << v + 1 << " " << u + 1 << " " << v + 1 << "\n";
		flag = true;
		exit(0);
	    }
	    else{
		ans.push_back(u+1);
		int64_t t = u + 1;
		while(parent[u] != parent[v]){
		    ans.push_back(parent[u]+1);
		    u = parent[u];
		}
		ans.push_back(t);
		reverse(ans.begin(), ans.end());
		cout << ans.size() << "\n";
		for(auto i : ans) cout << i << " ";
		flag = true;
		exit(0);
	    }	// back edge / aka non-trivial cycle
	}else if(vis[v] == 1){
	    ; // forward/cross edge
	}
    }
    vis[u] = 1;
}

// adj.resize(n);
// parent.resize(n, -1);
// vis.resize(n, -1);

void solve(){
    int64_t m; cin >> n >> m;
    adj.resize(n);
    parent.resize(n, -1);
    vis.resize(n, -1);
    for(int i = 0; i < m; ++i){
	int64_t u, v; cin >> u >> v;
	--u, --v;
	adj[u].push_back(v);
    }
    flag = false;
    for(int i = 0; i < n; ++i)
	if(vis[i] == -1) cycle(i);
    if(!flag) cout << "IMPOSSIBLE" << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

