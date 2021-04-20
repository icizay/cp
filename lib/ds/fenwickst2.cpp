const int mxN = 1e5 + 5;

#define lsb(s) (s & -(s))

template <typename T>
struct ftw{
	int n; T bits[mxN];

	ftw(int _n){
		this -> n = _n;
	}

	void add(int pos, T val){
		while(pos <= n){
			bits[pos] += val;
			pos += lsb(pos);
		}
	}
	T qry(int pos){
		T res = 0;
		while(pos > 0){
			res += bits[pos];
			pos -= lsb(pos);
		}
		return res;
	}
	T qry(int l, int r){
		return qry(r) - qry(l - 1);
	}
};
