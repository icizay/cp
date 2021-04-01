#include <bits/stdc++.h>
using namespace std;

#define ll int64_t

int n, m; 
const int N = 1e5 + 2;
ll st[2 * 4 * N];
ll A[2 * N];

void upd(int pos, int val, int cur = 1, int l = 0, int r = 2 * n - 1){
	if(pos > r || pos < l) return;
    if(l == r){
	st[cur] = val;
	return;
    }
    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur] = st[cur * 2] + st[cur * 2 + 1];  
}
 
ll qry(int bl, int br, int cur = 1, int l = 0, int r = 2 * n - 1){
    if(l >= bl && r <= br) return st[cur];
    if(br < l || r < bl) return 0;

    int mid = (l + r) / 2;

    ll ls = qry(bl, br, 2 * cur, l, mid);
    ll rs = qry(bl, br, 2 * cur + 1, mid + 1, r);

    return ls + rs;
}

void solve(){
	cin >> n;
	for(int i = 0; i < 2 * n; ++i){
		cin >> A[i];
	}
	vector<ll> ans(2 * N + 1);
	unordered_map<int, int> loc;

	for(int i = 0; i < 2 * n; ++i){
		if(loc.count(A[i])){
			int pos = loc[A[i]];
			ll sum = qry(pos, i);
			ans[A[i]] = sum;
			upd(pos, 1);
		}else{
			loc[A[i]] = i;
		}
	}

	for(int i = 1; i <= n; ++i) cout << ans[i] << " ";

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
