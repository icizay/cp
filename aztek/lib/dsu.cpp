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

