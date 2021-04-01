#include <bits/stdc++.h>
using namespace std;

// no negative weight
// adj[u, v, w]

#define ll long long

const ll INF = 1e12;
const int N = 1e5 + 5;
vector<vector<pair<int,int>>> adj(N);
ll dist[N];
bool processed[N];

int p[N];

void solve(){
    int n, m; cin >> n >> m;
    int s = 0, e = n - 1;
    for(int i = 0; i < n; ++i){
	dist[i] = INF;
	processed[i] = false;
    }
    for(int i = 0; i < m; ++i){
	int u, v, w; cin >> u >> v >> w;
	--u, --v;
	adj[u].push_back({v, w});
	adj[v].push_back({u, w});
    }

    priority_queue<pair<int, int>> q;
    dist[s] = 0;
    q.push({0,s});
    while(!q.empty()){
	int a = q.top().second; q.pop();
	if(processed[a]) continue;
	processed[a] = true;
	for(auto u : adj[a]){
	    int b = u.first, w = u.second;
	    if(dist[a]+w < dist[b]){
		dist[b] = dist[a] + w;
		p[b] = a; // path
		q.push({-dist[b], b});
	    }
	}
    }

    if(!processed[e]){
	cout << -1 << "\n";
	return;
    }

    vector<int> path;

    for(int v = e; v != s; v = p[v])
	path.push_back(v);
    path.push_back(s);

    reverse(path.begin(), path.end());

    //cout << dist[e] << "\n";

    for(auto i : path) cout << i + 1 << " ";
}

/*

   5 6
   1 2 2
   2 5 5
   2 3 4
   1 4 1
   4 3 3
   3 5 1

answer: 1 4 3 5

10 10
1 5 12
2 4 140
2 10 149
3 6 154
3 7 9
3 8 226
3 10 132
4 10 55
5 8 33
7 8 173

answer: 1 5 8 7 3 10
*/


int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

