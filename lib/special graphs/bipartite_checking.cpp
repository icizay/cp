bool bpt(){
	int s = 0;
	queue<int> q; q.push(s);
	vector<int> color(n, -1); color[s] = 0;
	while(!q.empty()){
		int u = q.front(); q.pop();
		for(auto &v: adj[u]){
			if(color[v] == -1){
				color[v] = 1 - color[u];
				q.push(v);
			}
			else if(color[v] == color[u]){
				return false;
			}
		}
	}
	return true;
}



