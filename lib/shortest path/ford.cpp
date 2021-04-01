vector<array<int, 3>> edges;
const int INF = 1 << 30;
int n;
vector<int> dist;
// edge list
// O(n*m)

void ford(int node){
    dist[node] = 0; // start from node
    for(int i=0; i<n-1; ++i){
	bool modified = false;
	for(auto [u, v, w] : edges){
	    if(dist[u] + w < dist[v]) modified = true;
	    dist[v] = min(dist[v], dist[u]+w);
	}
	if(!modified) break;
    }
}

// if last round reduces any distance then there is negative cycle
bool negative_cycle(){
    for(int i = 0; i < n; ++i)
	for(auto [u, v, w] : edges)
	    if(dist[v] > dist[u] + w)
		return true;
    return false;    
}

// edges.resize(m);
// dist.resize(n, INF);
// directed graph
