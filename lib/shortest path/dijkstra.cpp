// no negative weight
// adj[u, v, w]
const int64_t INF = 1e12;
vector<vector<array<int64_t, 2>>> adj;
vector<int64_t> dist;
vector<bool> processed;

// vector<int> p // path

/*
   void exp_path(vector<int> &path, int s, int e){
   for(int v = e; v != s; v = p[v])
   path.emplace_back(v);
   path.emplace_back(s);

   reverse(path.begin(), path.end());
   }
*/

// inside main()
dist.resize(n, INF);
processed.resize(n, false);
adj.resize(n);
//p.resize(n);
priority_queue<array<int64_t, 2>> q;
int s; // starting node
dist[s] = 0;
q.push({0,s});
while(!q.empty()){
    int a = q.top()[1]; q.pop();
    if(processed[a]) continue;
    processed[a] = true;
    for(auto [b,w] : adj[a]){
	if(dist[a]+w < dist[b]){
	    dist[b] = dist[a] + w;
	    // p[b] = a; // path
	    q.push({-dist[b], b});
	}
    }
}
