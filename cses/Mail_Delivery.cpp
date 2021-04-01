#include <bits/stdc++.h>
using namespace std;
 
int n, sz;
const int N = 4 * 1e5 + 5;
vector<vector<array<int, 2>>> adj(N);
vector<bool> vis(N, false);
vector<int> ans;
 
void solve(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	adj[u].push_back({v,i});
	adj[v].push_back({u,i});
    }
 
    for(int i = 1; i <= n; ++i)
	if(adj[i].size() & 1){
	    cout << "IMPOSSIBLE" << "\n";
	    return;
	}

    vector<int> st = {1};
    while(!st.empty()){
	int v = st.back();
	bool f = false;
	while(!adj[v].empty()){
	    auto [u, i] = adj[v].back(); adj[v].pop_back();
	    if(!vis[i]){
		st.push_back(u); vis[i] = 1; f = true;
		break;
	    }
	}
	if(!f){
	    ans.push_back(v); st.pop_back();
	}
    }

    if(ans.size() != m + 1) cout << "IMPOSSIBLE" << "\n";
    else for(auto i : ans) cout << i << " ";
    

 
 
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
