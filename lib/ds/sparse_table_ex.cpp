#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

const int mxN = 1e5 + 5, lg = 17;
ll a[mxN], st[mxN][lg];

/*

https://codeforces.com/edu/course/2/lesson/9/2/practice/contest/307093/problem/G

*/

ll qry(int l, int r){
	int len = r - l + 1;
	if(len == 0) return 0;
	int k = 31 - __builtin_clz(len);
	return gcd(st[l][k], st[r - (1 << k) + 1][k]);
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i){
		st[i][0] = a[i];
	}
	for(int k = 1; k < lg; ++k){
		for(int i = 0; i + (1 << k) - 1 < n; ++i){
			st[i][k] = gcd(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
		}
	} 

	ll ans = 1e18;
	for(int i = 0; i < n; ++i){
		int l = i, r = n - 1;
		while(r - l > 1){
			int mid = (l + r) / 2;
			if(qry(i, mid) == 1){
				r = mid;
			}else{
				l = mid;
			}
		}
		if(qry(i, r) == 1) ans = min(ans, (ll)r + 1 - i);
		if(qry(i, l) == 1) ans = min(ans, (ll)l + 1 - i);
	}

	if(ans == 1e18) cout << -1 << "\n";
	else cout << ans << "\n";


}