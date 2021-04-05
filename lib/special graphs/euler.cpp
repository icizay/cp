void euler(int s){
	vector<int> st;
	st.emplace_back(s);
	while(!st.empty()){
		int u = st.back();
		if(idx[u] < (int)adj[u].size())
			st.push_back(adj[u][idx[u]++]);
		else{
			ans.emplace_back(u);
			st.pop_back();
		}
	}
	reverse(ans.begin(), ans.end());
}

// for directed graphs,
// note: to an euler cycle to be exist, for all nodes, in degree and out degree of the node should be equal
//     a) There should be a single vertex in graph which has (indegree+1==outdegree), lets call this vertex 'an'.
//     b) There should be a single vertex in graph which has (indegree==outdegree+1), lets call this vertex 'bn'.
//     c) Rest all vertices should have (indegree==outdegree)
//

// for undirected graphs
// all vertices should have even degree to get an euler cycle 
// if exactly two vertices have odd number of edges, then we 
// can start from one of these two and we will get an euler path.

bool possible(int &s){ 
	int a = 0, b = 0;
	for(int i = 0; i < sz; ++i){
		if(abs(in_degree[i] - out_degree[i]) >= 2) return false;
		if(in_degree[i] + 1 == out_degree[i]) s = i;
		a += (in_degree[i] - out_degree[i] == 1);
		b += (in_degree[i] + 1 ==  out_degree[i]);
	}
	return (a == b && a <= 1);
}
