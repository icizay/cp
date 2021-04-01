// not really sure ig
// cycle can be restored with parent array

int n;
vector<int> parent;
vector<int> vis;
vector<vector<int>> adj;

// -1 = unvisited
// 0 = explored
// 1 = visited

void cycle(int u){
    vis[u] = 0;
    for(auto &v : adj[u]){
	if(vis[v] == -1){ // part of dfs spanning tree
	    parent[v] = u;
	    cycle(v); 
	}else if(vis[v] == 0){ // cycle 
	    if(parent[u] == v); // trivial cycle / aka bidirectional edge
	    else; // back edge / aka non-trivial cycle
	}else if(vis[v] == 1){
	    ; // forward/cross edge
	}
    }
    vis[u] = 1;
}

// adj.resize(n);
// parent.resize(n, -1);
// vis.resize(n, -1);


