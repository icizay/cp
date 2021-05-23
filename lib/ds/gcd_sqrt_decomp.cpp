#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

// sqrt decomp for GCD

int N, block_size;
const int mxN = 1e5 + 5;
int a[mxN], b[mxN];

void upd_intv(int i){
	int idx = i / block_size * block_size;
	b[idx] = a[idx];
	for(int i = idx; i < idx + block_size; ++i)
		b[idx] = gcd(b[idx], a[i]);
}

void upd(int i, int v) {  a[i] = v; upd_intv(i); }

int qry(int l, int r){
	int ans = 0;
	for(int i = l; i <= r; ){
		if(i % block_size == 0 && (i + block_size - 1 <= r))
			ans = gcd(ans, b[i]), i += block_size;
		else
			ans = gcd(ans, a[i]), ++i;
	}
	return ans;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	N = 8; block_size = sqrt(N) + 1;
	int c[] = {10,5,10,1,10,5,7,21};
	for(int i = 0; i < N; ++i){
		a[i] = c[i];
		upd(i, a[i]);
	}
	for(int i = 0; i < N; ++i){
		for(int j = i + 1; j < N; ++j){
		int brute_gcd = 0;
		for(int x = i; x <= j; ++x) brute_gcd = gcd(brute_gcd, a[x]);
		assert(brute_gcd == qry(i, j));
		}
	}
}
