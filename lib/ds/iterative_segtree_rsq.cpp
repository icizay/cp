struct segtree{
	int N = 1e5 + 5; ll KEK = 0;
	vector<ll> st;
	segtree(int _N, ll _KEK) : N(_N), KEK(_KEK) {
		st.resize(4 * N);
	}

	ll f(ll x, ll y){ return min(x, y);}

	void build() {
		for(int i = N - 1; i > 0; --i) st[i] = f(st[i << 1], st[i << 1 | 1]);
	}

	void upd(int p, ll val) { 
		for(st[p += N] = val; p > 1; p >>= 1) st[p >> 1] = f(st[p], st[p ^ 1]);
	}

	ll qry(int l, int r){ 
		ll res = KEK;
		for(l += N, r += N; l < r; l >>= 1, r >>= 1){
			if (l & 1) res = f(res, st[l++]);
			if (r & 1) res = f(res, st[--r]);
		}
		return res;
	}
};
