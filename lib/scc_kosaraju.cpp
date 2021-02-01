int n, scc; 
vector<vector<array<int, 2>>> adj, t_adj; // normal and transposed adj
vector<int> s;
vector<bool> vis;

void dfs(int u, int pass){
	vis[u] = true;
	vector<array<int, 2>> neighbor = (pass == 1) ? adj[u] : t_adj[u];
	for(auto &[v, w] : neighbor)
		if(!vis[v])
			dfs(v, pass);
	s.emplace_back(u);
}

// adj.resize(n)
// t_adj.resize(n)
// s.clear()
// vis.resize(n, -1)

// in main()

for(int i = 0; i < n; ++i)
		if(!vis[i]) dfs(i, 1);

	vis.assign(n, false);

	for(int i = n - 1; i >= 0; --i)
		if(!vis[s[i]])
			++scc, dfs(s[i], 2);
