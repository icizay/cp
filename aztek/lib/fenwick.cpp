struct fenwick{
    vector<int> bits;
    int sz;
    
    fenwick(int n){
	bits.resize(n + 2, 0);
	this -> sz = n + 2;
    }

    void upd(int x, int d){
	while(x < sz){
	    bits[x] += d;
	    x |= (x+1);
	}
    }

    int get(int x){
	int res = 0;
	while(x > 0){
	    res += bits[x];
	    x = (x & (x + 1)) - 1;
	}
	return res;
    }

    int get(int x, int y){
	return get(y) - get(x - 1);
    }
};
