#include <bits/stdc++.h>
using namespace std;

// no negative weight
// adj[u, v, w]
int n, m, k;
const int64_t INF = 1e18;
vector<vector<array<int64_t, 2>>> adj;
vector<int64_t> cnt;

void solve(){
    cin >> n >> m >> k;
    adj.resize(n);
    cnt.resize(n, 0);

    for(int i = 0; i < m; ++i){
	int64_t u, v, w; cin >> u >> v >> w;
	--u, --v;
	adj[u].push_back({v, w});
    }

    priority_queue<array<int64_t, 2>> q;
    int s = 0;
    q.push({0,s});
    while(!q.empty() && cnt[n - 1] < k){
	int64_t d = q.top()[0], a = q.top()[1];
	q.pop();
	cnt[a]++;
	if(a == n - 1) cout << -d << "  ";
	if(cnt[a] <= k) for(auto [b, w] : adj[a]) q.push({d - w, b});
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

