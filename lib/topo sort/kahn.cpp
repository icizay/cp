int n;
vector<vector<int>> adj;
vector<int> in_degree;

void kahn(vector<int> &order){
    priority_queue<int, vector<int>, greater<int>> pq;
    for(int i = 0; i < n; ++i)
	if(in_degree[i] == 0) pq.push(i);
    while(!pq.empty()){
	int u = pq.top(); pq.pop();
	order.emplace_back(u);
	for(auto &v : adj[u]){
	    --in_degree[v];
	    if(in_degree[v] <= 0) pq.push(v);
	}   
    }
}

