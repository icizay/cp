template <typename T>
struct fwt{
	int n; vector<T> bits;
	fwt(int _n) : n(_n){
		bits.resize(n, 0);
	}
	void add(int pos, T val){
		while(pos < n){
			bits[pos] += val;
			pos |= (pos + 1);
		}
	}
	T qry(int pos){
		T res = 0;
		while(pos >= 0){
			res += bits[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
	T qry(int l, int r){
		return qry(r) - qry(l - 1);
	}
};
