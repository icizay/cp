#include <bits/stdc++.h>
using namespace std;

const int N = 1 << 20; // limits kid
int n, m;

struct node{
    int64_t v, sum, kek;
} st[4 * N], lazy[4 * N];

void upd(int pos, int64_t val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur].v = st[cur].sum = val;
	return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur].sum = st[cur * 2].sum + st[cur * 2 + 1].sum;
}

void push(int cur, int l, int r){
    if(lazy[cur].v == 0) return; // no need to update anything kids
    st[cur].sum += (r - l + 1) * lazy[cur].v;
    if(l != r){ // if not a leaf
	lazy[cur * 2].v += lazy[cur].v; // (push lazy to children) keep in mind (lazy[def] = 0) may be dum for some cases
	lazy[cur * 2 + 1].v += lazy[cur].v;
    }
    lazy[cur].v = 0;
}

void push_set(int cur, int l, int r){
    if(lazy[cur].kek == 0) return;
    st[cur].sum = (r - l + 1) * lazy[cur].kek;
    if(l != r){
	lazy[cur * 2].kek = lazy[cur].kek;
	lazy[cur * 2 + 1].kek = lazy[cur].kek;
    }
    lazy[cur].kek = 0;
}

void r_upd(int bl, int br, int64_t val, int cur = 1, int l = 0, int r = n - 1){
    push(cur, l, r);
    push_set(cur, l, r);
    if(l > br || r < bl) return;
    if(bl <= l && r <= br){
	if(l != r){ // if not leaf
	    lazy[cur].v += val;
	    push(cur, l, r);
	}else{
	    st[cur].sum += val;
	}
	return;
    }

    int mid = (l + r) / 2;
    r_upd(bl, br, val, cur * 2, l, mid);
    r_upd(bl, br, val, cur * 2 + 1, mid + 1, r);
    st[cur].sum = st[cur * 2].sum + st[cur * 2 + 1].sum; 
}

void r_set(int bl, int br, int64_t val, int cur = 1, int l = 0, int r = n - 1){
    push(cur, l, r);
    push_set(cur, l, r);
    if(l > br || r < bl) return;
    if(bl <= l && r <= br){
	if(l != r){
	    lazy[cur].kek = val;
	    push_set(cur, l, r);
	}else{
	    st[cur].sum = val;
	}
	return;
    }
    int mid = (l + r) / 2;
    r_set(bl, br, val, cur * 2, l, mid);
    r_set(bl, br, val, cur * 2 + 1, mid + 1, r);
    st[cur].sum = (r - l + 1) * lazy[cur].kek;
}


int64_t qry(int bl, int br, int cur = 1, int l = 0, int r = n - 1){
    push(cur, l, r);
    push_set(cur, l, r);
    if(l >= bl && r <= br) return st[cur].sum;
    if(l > br || r < bl) return 0;
    int mid = (l + r) / 2;
    int64_t ls = 0, rs = 0;
    if(bl <= mid)
	ls = qry(bl, br, cur * 2, l, mid);
    if(mid <= br)
	rs = qry(bl, br, cur * 2 + 1, mid + 1, r);
    return ls + rs;
}

void solve(){
    int q; cin >> n >> q;
    for(int i = 0; i < n; ++i){
	int64_t x; cin >> x;
	upd(i, x);
    }
    while(q--){
	int t, a, b, x; cin >> t >> a >> b;
	--a, --b;
	if(t == 1){
	    cin >> x;
	    r_upd(a,b,x);
	}else if(t == 2){
	    r_set(a,b,x);
	}else{
	    cout << qry(a,b) << "\n";
	}
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

