#include <bits/stdc++.h>
using namespace std;

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


void solve(){
    int m; cin >> n >> m;
    adj.resize(n);
    in_degree.resize(n, 0);
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	--u, --v;
	adj[u].push_back(v);
	in_degree[v]++;
    }
    vector<int> order;
    kahn(order);
    vector<int> s(n), dp(n, -1), q(n, -1);
    for(int i = 0; i < n; ++i){
	int u = order[i];
	if(u == n - 1) break;
	if(!u) dp[u] = 1;
	if(dp[u] > 0)
	    for(int v : adj[u])
		if(dp[v] < dp[u] + 1) dp[v] = dp[u] + 1, q[v] = u;
    }

    if(dp[n-1] < 0){
       	cout << "IMPOSSIBLE" << "\n";
	return;
    }

   int v = n - 1;
   vector<int> ans = {v};
   while(q[v] != -1){
       ans.emplace_back(q[v]);
       q[v] = q[q[v]];
   }

   cout << ans.size() << "\n";
  for(int i = ans.size() - 1; i >= 0; --i)
     cout << ans[i] + 1 << " "; 

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

