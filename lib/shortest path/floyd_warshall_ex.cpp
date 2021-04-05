#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

const int LIM = 1e3 + 5;

ll dp[LIM][LIM];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n, m, q; cin >> n >> m >> q;

	for(int i = 0; i < LIM; ++i)
		for(int j = 0 ; j < LIM; ++j)
			if(i != j)
				dp[i][j] = 1e18;


	for(int i = 0; i < m; ++i){
		ll u, v, w; cin >> u >> v >> w;
		--u, --v;
		dp[u][v] = min(dp[u][v], w);
		dp[v][u] = min(dp[v][u], w);
	}
	for(int k = 0; k < n; ++k)
		for(int i = 0; i < n; ++i)
			for(int j = 0; j < n; ++j)
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
	while(q--){
		int u, v; cin >> u >> v; --u, --v;
		if(dp[u][v] == 1e18) cout << -1 << "\n";
		else cout << dp[u][v] << "\n";
	}
}
