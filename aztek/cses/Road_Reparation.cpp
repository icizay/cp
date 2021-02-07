#include <bits/stdc++.h>
using namespace std;

class dsu{                                
    private:
	vector<int> p, r, sz;                 
	int num_of_set;
    public:
	dsu(int N){
	    p.assign(N, 0); 
	    r.assign(N, 0);                       
	    sz.assign(N, 1);                        
	    iota(p.begin(), p.end(), 0);
	    num_of_set = N;                         
	}

	int get(int i) { return (p[i] == i ? i : p[i] = get(p[i])); } // be careful
	bool same(int i, int j) { return get(i) == get(j); }
	int setnum() { return num_of_set; }     
	int setsize(int i) { return sz[get(i)]; } 

	void unite(int x, int y) {                 
	    x = get(x), y = get(y);			 
	    if(x == y) return;                          
	    if (r[x] > r[y]) swap(x, y);          
	    p[x] = y;                            
	    if (r[x] == r[y]) ++r[y];         
	    sz[y] += sz[x];                    
	    --num_of_set;                              
	}
};


void solve(){
    int n, m; cin >> n >> m;
    dsu ds(n);
    vector<array<int, 3>> edges(m);
    for(int i = 0; i < m; ++i){
	cin >> edges[i][1] >> edges[i][2] >> edges[i][0]; 
	--edges[i][1]; --edges[i][2];
    }
    int64_t cost = 0;
    sort(edges.begin(), edges.end());
    for(auto &[w, u, v] : edges){
	if(ds.setnum() == 1) break;
	if(!ds.same(u, v)){
	    cost += w;
	    ds.unite(u,v);
	}
    }

    if(ds.setnum() != 1) cout << "IMPOSSIBLE" << "\n";
    else cout << cost << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

