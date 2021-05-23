#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

// edmonds karp -> O(V*E^2) // https://cses.fi/problemset/task/1694/

const int mxN = 501; const ll INF = 1e18;
int n, m; vector<int> adj[mxN]; ll cap[mxN][mxN];

ll bfs(int s, int t, vector<int> &p){
	fill(all(p), -1); p[s] = -2;
	queue<array<ll, 2>> q; q.push({s, INF});
	while(!q.empty()){
		auto [u, flow] = q.front(); q.pop();
		for(auto &v : adj[u]){
			if(p[v] == -1 && cap[u][v]){
				p[v] = u; ll new_flow = min(flow, cap[u][v]);
				if(v == t) return new_flow;
				q.push({v, new_flow});
			}
		}
	}
	return 0;
}

ll mx_flow(int s, int t){
	ll flow = 0, new_flow = 0;
	vector<int> p(n);
	while(new_flow = bfs(s, t, p)){
		flow += new_flow;
		int u = t;
		while(u != s){
			int prev = p[u];
			cap[prev][u] -= new_flow;
			cap[u][prev] += new_flow;
			u = prev;
		}
	}
	return flow;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for(int i = 0; i < m; ++i){
		int u, v; ll w; cin >> u >> v >> w; --u, --v;
		adj[u].push_back(v); adj[v].push_back(u); cap[u][v] += w; 
	}
	cout << mx_flow(0, n - 1) << "\n";
}

