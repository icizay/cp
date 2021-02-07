#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

#define ls(x) (x & -(x))

struct fenwick{
    vector<ll> bits;
    int sz;
    
    fenwick(int n){
	bits.resize(n, 0);
	this -> sz = n;
    }

    void upd(int x, ll d){
	while(x < sz){
	    bits[x] += d;
	    x |= (x+1);
	}
    }

    void upd(int x, int y, ll d){
	upd(x, d);
	upd(y + 1, -d);
    }

    ll get(int x){
	ll res = 0;
	while(x >= 0){
	    res += bits[x];
	    x = (x & (x + 1)) - 1;
	}
	return res;
    }
};

void solve(){
    int n, q; cin >> n >> q;
    fenwick ds(n+1);
    ll a[n];
    for(int i = 0; i < n; ++i){
	cin >> a[i];
    }
    for(int i = 0; i < n; ++i){
	ds.upd(i, i, a[i]);
    }
    for(int i = 0; i < q; ++i){
	int t; cin >> t;
	if(t == 1){
	    ll aa, bb, uu; cin >> aa >> bb >> uu;
	    --aa, --bb;
	    ds.upd(aa,bb,uu);
	}else{
	    int k; cin >> k;
	    --k;
	    cout << ds.get(k) << "\n";
	}
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

