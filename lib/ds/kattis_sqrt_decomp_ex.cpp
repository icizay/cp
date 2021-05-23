#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

// https://open.kattis.com/problems/modulodatastructures

const int SZ = 500, N = 2e5 + 5;
int n, q; 
ll inc[SZ + 5][SZ + 5], a[N];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	cin >> n >> q;
	while(q--){
		int T; cin >> T;
		if(T == 1){
			int A, B, C; cin >> A >> B >> C;
			if(B < SZ){
				inc[B][A] += C;
			}else{
				for(int i = A; i <= n; i += B) a[i] += C;
			}
		}else{
			int B; cin >> B;
			ll _A = a[B];
			for(int i = 1; i < SZ; ++i) _A += inc[i][B % i];
			cout << _A << "\n";
		}
	}

}
