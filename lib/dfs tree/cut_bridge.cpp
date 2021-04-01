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

	    if(low[v] >= num[u]) // check if u is a cut vertex
		cut_vertex[u] = 1;
	    
	    if(low[v] > num[u]) // check if (u,v) is a bridge
		; // edge u,v is bridge
	    
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
