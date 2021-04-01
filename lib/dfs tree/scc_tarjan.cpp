int n, iter, scc;
vector<vector<array<int, 2>>> adj;
vector<int> num, low;
vector<bool> vis;
stack<int> st;

void dfs(int u){
	low[u] = num[u] = iter++;
	st.push(u);
	vis[u] = true;
	for(auto &[v, w] : adj[u]){
		if(num[v] == -1) dfs(v);
		if(vis[v]) low[u] = min(low[u], low[v]);
	}
	if(low[u] == num[u]){
		++scc;
		while(true){
			int v = st.top(); st.pop();
			vis[v] = false;
			if(u == v) break;
		}
	}
}

// adj.resize(n)
// num.resize(n, -1)
// low.resize(n, 0)
// vis.assign(n, false)
// iter = scc = 0
// clear st if needed, normal dfs in main
