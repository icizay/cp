#include <bits/stdc++.h>
using namespace std;

vector<vector<array<int, 2>>> adj;
int n, iter, root, root_child;
vector<int> num, low, parent, cut_vertex;

void dfs(int u){
    low[u] = num[u] = iter++;
    for(auto &[v, w] : adj[u]){
	if(num[v] == -1){ // if unvisited(tree edge)
	    parent[v] = u;
	    if(root == u) ++root_child;

	    dfs(v);

	    if(low[v] >= num[u]) // cut vertex
		cut_vertex[u] = 1;
	    
	    if(low[v] > num[u]) // bridge
		cout << u << " " << v << "is a bridge" << "\n"; // edge u,v is bridge
	    
	    low[u] = min(low[u], low[v]); //subtree, always update
	}

	else if(v != parent[u]) // if non-trivial cycle
	    low[u] = min(low[u], num[v]); // then update
    }
}

// adj.resize(n);
// num.assign(n, -1)
// low.assign(n, 0)
// parent.assign(n, -1)
// cut_vertex.assign(n, 0);
// iter = 0
// must be an undirected graph

void solve(){
    int m; cin >> n >> m;
    adj.resize(n);
    num.assign(n, -1);
    low.assign(n, 0);
    parent.assign(n, -1);
    cut_vertex.assign(n, 0);
    iter = 0;
    for(int i = 0; i < m; ++i){
	int u, v, w; cin >> u >> v >> w;
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    cout << "Bridges:" << "\n";
    for(int i = 0; i < n; ++i){
	if(num[i] == -1){
	    root = i, root_child = 0;
	    dfs(i);
	    cut_vertex[root] = (root_child > 1);
	}
    }

    cout << "Cut vertices / aka Articulation points" << "\n";
    for(int i = 0; i < n; ++i){
	if(cut_vertex[i]) cout << i << " " << "is a cut vertice" << "\n";
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

