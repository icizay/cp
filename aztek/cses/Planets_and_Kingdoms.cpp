#include <bits/stdc++.h>
using namespace std;


int n, m, scc; 
vector<vector<int>> adj, t_adj; // normal and transposed adj
vector<int> s, ans;
vector<bool> vis;

void dfs(int u, int pass){
    vis[u] = true;
    vector<int> neighbor = (pass == 1) ? adj[u] : t_adj[u];
    for(auto &v : neighbor)
	if(!vis[v]){
	    if(pass == 2)
		ans[v] = ans[u];
	    dfs(v, pass);
	}
    s.emplace_back(u);
}

// adj.resize(n)
// t_adj.resize(n)
// s.clear()
// vis.resize(n, -1)

void solve(){
    cin >> n >> m;
    ans.resize(n, 0);
    iota(ans.begin(), ans.end(), 0);
    adj.resize(n); t_adj.resize(n);
    s.clear(); vis.resize(n, false);

    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	--u, --v;
	adj[u].push_back(v);
	t_adj[v].push_back(u);
    }

    for(int i = 0; i < n; ++i)
	if(!vis[i]) dfs(i, 1);

    vis.assign(n, false);

    for(int i = n - 1; i >= 0; --i)
	if(!vis[s[i]])
	    ++scc, dfs(s[i], 2);

    cout << scc << "\n";

    int j = 1;
    unordered_map<int, int> key;
    for(int i = 0; i < ans.size(); ++i){
	if(!key.count(ans[i])){
	    key[ans[i]] = j;
	    ++j; 
	}
	ans[i] = key[ans[i]];
    }

    for(auto i : ans) cout << i << " ";

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

