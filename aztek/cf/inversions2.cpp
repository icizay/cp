#include <bits/stdc++.h>
using namespace std;
 
#define ll int64_t

int n, m; 
const int N = 1e6;
ll st[4 * N];
ll a[N];
ll glb = -1;
 
void upd(int pos, ll val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = val;
	return;
    }
    
    if(pos > r || pos < l) return;

    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur] = st[cur * 2] + st[cur * 2 + 1];  
}
 
ll qry(ll &nm, int cur = 1, int l = 0, int r = n - 1){
    if(st[cur] == 0 || glb != -1) return INT_MAX;

    if(st[cur] < nm){
	nm -= st[cur];
	return INT_MAX;
    }

    if(l == r){
	glb = l;
	return l;
    }
    int mid = (r + l) / 2;
    ll left = qry(nm, cur * 2, l, mid);
    ll right = qry(nm, cur * 2 + 1, mid + 1, r);
    return min(left, right);
}
 
 
void solve(){
    cin >> n;
    for(int i = 0; i < n; ++i) cin >> a[i];
    ll ans = n;
    vector<ll> kek;
    for(int i = 0; i < n; ++i) upd(i, 1);
    for(int i = n - 1; i >= 0; --i){
	glb = -1;
	ll y = a[i];
	y = ans - y;
	ll x = qry(y);
	upd(x, 0);
	kek.push_back(x);
	--ans;
    }
    reverse(kek.begin(), kek.end());
    for(auto i : kek) cout << i + 1 << " ";
}
 
int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
