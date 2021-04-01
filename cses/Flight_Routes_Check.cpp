#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj[2];
vector<bool> vis;

void dfs(int u, int lel){
    vis[u] = true;
    for(auto j : adj[lel][u])
	if(!vis[j]) dfs(j, lel);
}

void solve(){
    int n,m; cin >> n >> m;
    adj[0].resize(n); adj[1].resize(n);
    vis.resize(n, false);
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	--u, --v;
	adj[0][u].push_back(v);
	adj[1][v].push_back(u);
    }
    dfs(0, 0);
    for(int i = 0; i < n; ++i){
	if(!vis[i]){
	    cout << "NO" << "\n";
	    cout << 1 << " " << i + 1 << "\n";
	    return;
	}
    }
    vis.assign(n, 0);
    dfs(0, 1);
    for(int i = 0; i < n; ++i){
	if(!vis[i]){
	    cout << "NO" << "\n";
	    cout << i + 1 << " " << 1 << "\n";
	    return;
	}
    }

    cout << "YES" << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

