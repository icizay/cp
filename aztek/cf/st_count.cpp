#include <bits/stdc++.h>
using namespace std;

int64_t INF = 1000000000;

struct node{
    int64_t c = INF, co = 0;
};

int n;
const int N = 1e6;
node st[4 * N];
int64_t a[N];

// RMQ, with counts!
node f(node _a, node _b){
    if(_a.c < _b.c) return _a;
    if(_b.c < _a.c) return _b;
    return {_a.c, _a.co + _b.co}; 
}

void upd(int pos, int64_t val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = {val, 1};
	a[cur] = val;
	return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur] = f(st[cur * 2], st[cur * 2 + 1]);
}

node qry(int bl, int br, int cur = 1, int l = 0, int r = n - 1){
    if(l > br || r < bl) return {INF, 0};
    if(l >= bl && r <= br) return st[cur];

    int mid = (l + r) / 2;
    node ls = {INF, 0}, rs = {INF, 0};
    if(bl <= mid)
	ls = qry(bl, br, cur * 2, l, mid);	
    if(br > mid)
	rs = qry(bl, br, cur * 2 + 1, mid + 1, r);

    return f(ls, rs);
}


void solve(){
    int m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
	cin >> a[i];
	upd(i, a[i]);
    }
    for(int i = 0; i < m; ++i){
	int a_, b_, c_;
	cin >> a_ >> b_ >> c_;
	if(a_ == 1){
	    upd(b_, c_);
	}else{
	    cout << qry(b_, c_-1).c << " " << qry(b_, c_-1).co  << "\n";
	}
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

