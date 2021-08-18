#include <bits/stdc++.h>
using namespace std;

int64_t INF = 1000000000;

struct node{
    int64_t sum, pref, suf, ans;
};

int n;
const int N = 1e6;
node st[4 * N];
int64_t a[N];

// range max
node f(node aa, node bb){
    return {aa.sum + bb.sum, max(aa.pref, aa.sum + bb.pref), max(bb.suf, bb.sum + aa.suf), max({aa.ans, bb.ans, aa.suf + bb.pref})};
}

node init(int64_t val){
    int64_t mx = max((int64_t)0, val);
    return {val, mx, mx, mx};
}

void upd(int pos, int64_t val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = init(val);
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
    if(l > br || r < bl) return init(0);
    if(l >= bl && r <= br) return st[cur];

    int mid = (l + r) / 2;
    return f(qry(bl, min(br, mid), cur * 2, l, mid), qry(max(bl, mid + 1), br, cur * 2 + 1, mid + 1, r));
}


void solve(){
    int m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
	cin >> a[i];
	upd(i, a[i]);
    }
    cout << st[1].ans << "\n";
    for(int i = 0; i < m; ++i){
	int p, vl; cin >> p >> vl;
	upd(p, vl);
	cout << st[1].ans << "\n";
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

