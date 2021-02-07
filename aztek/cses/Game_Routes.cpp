#include <bits/stdc++.h>
using namespace std;

int n, m;
const int mod = 1e9+7;
vector<vector<int>> adj, t_adj;
vector<int> in_degree;
vector<int> dp;

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

	for(auto &v: t_adj[u]){
	    dp[u] = (dp[u] + dp[v]) % mod; 
	}
    }
}

void solve(){
    cin >> n >> m;
    adj.resize(n); t_adj.resize(n);
    in_degree.resize(n, 0);
    dp.resize(n, 0);
    dp[0] = 1;
    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	--u, --v;
	adj[u].push_back(v);
	t_adj[v].push_back(u);
	in_degree[v]++;
    }
    vector<int> order;
    kahn(order);
    cout << dp[n - 1] << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

