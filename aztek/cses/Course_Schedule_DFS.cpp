#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> adj;
vector<bool> vis;

vector<int> order;

void dfs(int v){
    vis[v] = true;
    for(auto u : adj[v])
	if(!vis[u])
	    dfs(u);
    order.push_back(v);
}

void solve(){
    int m; cin >> n >> m;
    adj.resize(n);
    vis.resize(n, false);
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	--u, --v;
	adj[u].push_back(v);
    }

    for(int i = 0; i < n; ++i)
	if(!vis[i]) dfs(i);

    reverse(order.begin(), order.end());

    bool ok = false;

    vector<int> loc(n, -1);
    for(int i = 0; i < n; ++i) loc[order[i]] = i;

    for(int i = 0; i < n; ++i){
	for(auto j : adj[i]){
	    if(loc[i] > loc[j]){
		ok = true;
		goto hell;
	    }
	}
    }

hell:

    if(ok) cout << "IMPOSSIBLE" << "\n";
    else for(auto i : order) cout << i + 1 << " ";

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

