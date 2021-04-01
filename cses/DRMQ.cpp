#include <bits/stdc++.h>
using namespace std;

// credits: https://github.com/stevenhalim/cpbook-code

class SegmentTree {                              // OOP style
	private:
	int n;                                         // n = (int)A.size()
	vector<int> A, st, lazy;                                // the arrays

	int l(int p) { return  p<<1; }                 // go to left child
	int r(int p) { return (p<<1)+1; }              // go to right child

	int conquer(int a, int b) {
	    if (a == -1) return b;                       // corner case
	    if (b == -1) return a;
	    return min(a, b);                            // RMQ
	}

	void build(int p, int L, int R) {              // O(n)
	    if (L == R)
		st[p] = A[L];                              // base case
	    else {
		int m = (L+R)/2;
		build(l(p), L  , m);
		build(r(p), m+1, R);
		st[p] = conquer(st[l(p)], st[r(p)]);
	    }
	}

	void propagate(int p, int L, int R) {
	    if (lazy[p] != -1) {                         // has a lazy flag
		st[p] = lazy[p];                           // [L..R] has same value
		if (L != R)                                // not a leaf
		    lazy[l(p)] = lazy[r(p)] = lazy[p];       // propagate downwards
		else                                       // L == R, a single index
		    A[L] = lazy[p];                          // time to update this
		lazy[p] = -1;                              // erase lazy flag
	    }
	}

	int RMQ(int p, int L, int R, int i, int j) {   // O(log n)
	    propagate(p, L, R);                          // lazy propagation
	    if (i > j) return -1;                        // infeasible
	    if ((L >= i) && (R <= j)) return st[p];      // found the segment
	    int m = (L+R)/2;
	    return conquer(RMQ(l(p), L  , m, i          , min(m, j)),
		    RMQ(r(p), m+1, R, max(i, m+1), j        ));
	}

	void update(int p, int L, int R, int i, int j, int val) { // O(log n)
	    propagate(p, L, R);                          // lazy propagation
	    if (i > j) return;
	    if ((L >= i) && (R <= j)) {                  // found the segment
		lazy[p] = val;                             // update this
		propagate(p, L, R);                        // lazy propagation
	    }
	    else {
		int m = (L+R)/2;
		update(l(p), L  , m, i          , min(m, j), val);
		update(r(p), m+1, R, max(i, m+1), j        , val);
		int lsubtree = (lazy[l(p)] != -1) ? lazy[l(p)] : st[l(p)];
		int rsubtree = (lazy[r(p)] != -1) ? lazy[r(p)] : st[r(p)];
		st[p] = (lsubtree <= rsubtree) ? st[l(p)] : st[r(p)];
	    }
	}

    public:
	SegmentTree(int sz) : n(sz), st(4*n), lazy(4*n, -1) {}
	SegmentTree(const vector<int> &initialA) : SegmentTree((int)initialA.size()) {
	    A = initialA;
	    build(1, 0, n-1);
	}
	void update(int i, int j, int val) { update(1, 0, n-1, i, j, val); }
	int RMQ(int i, int j) { return RMQ(1, 0, n-1, i, j); }
};


void solve(){
    int n, m; cin >> n >> m;
    vector<int> aa(n);
    for(auto &v : aa) cin >> v;
    SegmentTree ds(aa);
    for(int i = 0; i < m; ++i){
	int type; cin >> type;
	if(type == 1){
	    int k, u; cin >> k >> u;
	    --k;
	    ds.update(k, k, u);
	}else if(type == 2){
	    int a, b; cin >> a >> b;
	    --a, --b;
	    cout << ds.RMQ(a, b) << "\n";
	}
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

