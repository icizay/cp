template<int mxN> struct DSU{                
	int p[mxN], r[mxN], sz[mxN];                 
	DSU(){
		for(int i = 0; i < mxN; ++i) p[i] = i, sz[i] = 1;
	}
	int get(int x){
		if(p[x] == x) return x;
		else return p[x] = get(p[x]);
	}
	int both(int x, int y) { return get(x) == get(y); }
	int size(int x) { return sz[get(x)]; } 
	void unite(int x, int y) {                 
	    x = get(x), y = get(y);			 
	    if(x == y) return;                          
	    if (r[x] > r[y]) swap(x, y);          
	    p[x] = y;                            
	    if (r[x] == r[y]) ++r[y];         
	    sz[y] += sz[x];                    
	}
};