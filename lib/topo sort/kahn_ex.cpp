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

// adj.resize(n);
// in_degree.resize(n, 0);

void solve(){
    int m; cin >> n >> m;
    adj.resize(n);
    in_degree.resize(n, 0);

    for(int i = 0; i < m; ++i){
	int u, v; cin >> u >> v;
	adj[u].push_back(v);
	in_degree[v]++;
    }


    vector<int> order;
    kahn(order);
    for(auto i : order) cout << i << " ";
}

/*

   6 6
   5 2
   5 0
   4 0
   4 1
   2 3
   3 1

ans: 5 4 3 2 1 0

*/

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

