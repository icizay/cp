#include <bits/stdc++.h>
using namespace std;
 
#define ll int64_t

int n, m; 
const int N = 1e6;
ll st[4 * N];
ll a[N];
 
void upd(int pos, int val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = val;
	a[cur] = val;
	return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur] = st[cur * 2] + st[cur * 2 + 1];  
}
 
ll qry(int bl, int br, int cur = 1, int l = 0, int r = n - 1){
    if(l >= bl && r <= br) return st[cur];
    if(br < l || r < bl) return 0;

    int mid = (l + r) / 2;

    ll ls = qry(bl, br, 2 * cur, l, mid);
    ll rs = qry(bl, br, 2 * cur + 1, mid + 1, r);

    return ls + rs;
}
 
 
void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
	cin >> a[i];
	upd(i, a[i]);
    }
    for(int i = 0; i < m; ++i){
	ll t, aa, bb; cin >> t >> aa >> bb;
	if(t == 1)
	    upd(aa, bb);
	else
	    cout << qry(aa, bb - 1) << "\n";
    }	
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
