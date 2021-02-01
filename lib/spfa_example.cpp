#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<array<int, 2>>> adj;
const int INF = 1 << 30;
vector<int> dist;
vector<int> cnt;
vector<int> in_queue;
queue<int> q;

bool ford(int node){
    dist[node] = 0; // start from node
    q.push(node);
    in_queue[node] = 1;
    while(!q.empty()){
	int u = q.front();
	q.pop();
	in_queue[u] = 0;
	for(auto [v, w] : adj[u]){
	    if(dist[u] + w < dist[v]){
		dist[v] = dist[u] + w;
		if(!in_queue[v]){
		    q.push(v);
		    in_queue[v] = 1;
		    cnt[v]++;

		    if(cnt[v] > n) return false;
		}
	    }
	} 
    }
    return true;
}

// returns true if there is no negative cycle, false else.

// adj.resize(n);
// dist.resize(n, INF);
// in_queue.resize(n, false);
// cnt.resize(n, 0);
// directed graph

void solve(){
    int m, s, e; cin >> n >> m >> s >> e;
    adj.resize(n);
    in_queue.resize(n, 0);
    dist.resize(n, INF);
    cnt.resize(n, 0);
    for(int i = 0; i < m; ++i){
	int u, v, w; cin >> u >> v >> w;
	adj[u].push_back({v, w});
    }

    if(ford(s)) cout << dist[e] << "\n";
    else cout << "NO" << "\n";
}

/*

   6 6 0 3
   0 1 99
   0 5 -99
   1 2 15
   2 3 0
   3 1 -42
   3 4 2

   (negative cycle)

   5 5 0 2
   0 1 1
   0 2 10
   1 3 2
   2 3 -10
   3 4 3

   (negative edge, but not cycle)

*/

int main(){
    int test = 1;
    while(test--) solve();
}

