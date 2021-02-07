#include <bits/stdc++.h>
using namespace std;
 
int n, m;
const int N = 4 * 1e5 + 5;
vector<vector<int>> adj(N);
int in[N], out[N];
vector<int> path;

void dfs(int s){
    while(adj[s].size()){
	int u = adj[s].back();
	adj[s].pop_back();
	dfs(u);
    }
    path.push_back(s);
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	--u, --v;
	adj[u].push_back(v);
	in[v]++; out[u]++;
    }

    int a, b, c, s1, s2;
    a = b = c = s1 = s2 = 0;
    for(int i = 0; i < n; ++i){
	if(in[i] - out[i] == 0) ++c;
	if(in[i] - out[i] == 1) {++b, s2 = i;}
	if(in[i] - out[i] == -1) {++a, s1 = i;}
    }

    if(s1 != 0 || s2 != n - 1){
	cout << "IMPOSSIBLE" << "\n";
	return;
    }

    if(!(c == n - 2 && a == 1 && b == 1)){
	cout << "IMPOSSIBLE" << "\n";
	return;
    }
    dfs(0);
    if(path.size() != m + 1) { cout << "IMPOSSIBLE" << "\n"; return;}
    reverse(path.begin(), path.end());
    for(auto j : path) cout << j + 1 << " ";
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
