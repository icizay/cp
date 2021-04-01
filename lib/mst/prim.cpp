vector<vector<array<int, 2>>> adj;
vector<int> vis;
priority_queue<array<int, 2>> pq;
// vector<array<int, 2>> mst; // figure out how to construct mst edges if possible without weird stuff
int n;

void process(int u){
    vis[u] = 1;
    for(auto &[v, w] : adj[u])
	if(!vis[v])
	    pq.push({-w, -v});
}

int mst(int start){
    vis.resize(n, 0);
    process(start);
    int cost = 0;
    int taken = 0;
    while(!pq.empty()){
	auto [w, u] = pq.top();
	w *= -1; u *= -1;
	pq.pop();
	if(vis[u]) continue;
	cost += w;
	process(u);
	++taken;
	if(taken == n - 1) break;
    }
    return cost;
}
