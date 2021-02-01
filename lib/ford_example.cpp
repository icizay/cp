#include <bits/stdc++.h>
using namespace std;

vector<array<int, 3>> edges;
const int INF = 1 << 30;
int n;
vector<int> dist;
// edge list
// O(n*m)

void ford(int node){
    dist[node] = 0; // start from node
    for(int i=0; i<n-1; ++i){
	bool modified = false;
	for(auto [u, v, w] : edges){
	    if(dist[u] + w < dist[v]) modified = true;
	    dist[v] = min(dist[v], dist[u]+w);
	}
	if(!modified) break;
    }
}

// if last round reduces any distance then there is negative cycle
bool negative_cycle(){
    for(int i = 0; i < n; ++i)
	for(auto [u, v, w] : edges)
	    if(dist[v] > dist[u] + w)
		return true;
    return false;    
}

// edges.resize(m);
// dist.resize(n, INF);

void solve(){
    int m; cin >> n >> m;
    int start, end; cin >> start >> end;
    edges.resize(m);
    dist.resize(n, INF);
    for(int i = 0; i < m; ++i){
	int u, v, w; cin >> u >> v >> w;
	edges.push_back({u, v, w});
    }	
    ford(start);
    if(negative_cycle()) cout << "negative cycle exist :pensive:" << "\n";
    else cout << dist[end];
}

/*

   5 7 2 3
   0 3 5
   0 4 3
   2 4 2
   4 3 10
   4 0 7
   2 1 5
   1 0 1

*/

/*

   4 4 0 2
   0 1 1
   1 2 -1
   2 3 -1
   3 0 -1

*/

int main(){
    int test = 1;
    while(test--) solve();
}

