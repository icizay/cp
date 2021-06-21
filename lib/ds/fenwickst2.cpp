#define lsb(s) (s & -(s))

template <typename T>
struct ftw{
	int n; vector<T> bits;
	ftw(int _n) : n(_n){
		bits.resize(n + 1, 0);
	}
	void add(int pos, T val){
		++pos;
		while(pos <= n){
			bits[pos] += val;
			pos += lsb(pos);
		}
	}
	T qry(int pos){
		++pos;
		T res = 0;
		while(pos > 0){
			res += bits[pos];
			pos -= lsb(pos);
		}
		return res;
	}
	T qry(int l, int r){
		++l, ++r;
		return qry(r) - qry(l - 1);
	}
};
