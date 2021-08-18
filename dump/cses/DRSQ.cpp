#include <bits/stdc++.h>
using namespace std;

struct fenwick{
    vector<int64_t> bits;
    int sz;
    
    fenwick(int n){
	bits.resize(n + 2, 0);
	this -> sz = n + 2;
    }

    void upd(int x, int64_t d){
	while(x < sz){
	    bits[x] += d;
	    x |= (x+1);
	}
    }

    int64_t get(int x){
	int64_t res = 0;
	while(x >= 0){
	    res += bits[x];
	    x = (x & (x + 1)) - 1;
	}
	return res;
    }

    int64_t get(int x, int y){
	return get(y) - get(x - 1);
    }
};

void solve(){
    int n, m; cin >> n >> m;
    fenwick ds(n);
    int64_t A[n];
    for(int i = 0; i < n; ++i){
	cin >> A[i];
	ds.upd(i, A[i]);
    }
    for(int i = 0; i < m; ++i){
	int64_t t, a, b; cin >> t >> a >> b;
	if(t == 1){
	    --a;
	    int64_t val = b - A[a];
	    A[a] = b;
	    ds.upd(a, val);
	}else if(t == 2){
	    --a, --b;
	    cout << ds.get(a, b) << "\n";
	}
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

