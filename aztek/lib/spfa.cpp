int n;
vector<vector<array<int, 2>>> adj;
const int INF = 1 << 30;
vector<int> dist;
vector<int> cnt;
vector<int> in_queue;
queue<int> q;

bool ford(int node){
    dist[node] = 0; // start from node
    q.push(node);
    in_queue[node] = 1;
    while(!q.empty()){
	int u = q.front();
	q.pop();
	in_queue[u] = 0;
	for(auto [v, w] : adj[u]){
	    if(dist[u] + w < dist[v]){
		dist[v] = dist[u] + w;
		if(!in_queue[v]){
		    q.push(v);
		    in_queue[v] = 1;
		    cnt[v]++;

		    if(cnt[v] > n) return false;
		}
	    }
	} 
    }
    return true;
}

// returns true if there is no negative cycle, false else.

// adj.resize(n);
// dist.resize(n, INF);
// in_queue.resize(n, false);
// cnt.resize(n, 0);
// directed graph

