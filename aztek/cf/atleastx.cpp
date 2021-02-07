#include <bits/stdc++.h>
using namespace std;

const int N = 1e6;
int64_t st[4 * N];
int64_t A[N]; int64_t n, m;
int64_t ans = -1;


void upd(int pos, int64_t val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = val;
	A[cur] = val;
	return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur] = max(st[cur * 2], st[cur * 2 + 1]);
}

void qry(int val, int bou, int cur = 1, int l = 0, int r = n - 1){
    if(st[cur] < val || ans >= 0 || r < bou) return;
    // r < bou, for the second prob
    // delete from all for first
    if(l == r){
	if(st[cur] >= val)
	    ans = l;
	return;
    }
    int mid = (l + r) / 2;
    qry(val, bou, cur * 2, l, mid);
    qry(val, bou, cur * 2 + 1, mid + 1, r);
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
	cin >> A[i];
	upd(i, A[i]);
    }
    for(int i = 0; i < m; ++i){
	int type; cin >> type;
	if(type == 1){
	    int j, v; cin >> j >> v;
	    upd(j, v);
	}else{
	    int v, bou; cin >> v >> bou;
	    ans = -1;
	    qry(v, bou);
	    cout << ans << "\n";
	}
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

