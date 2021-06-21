#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

const int mxN = 1e5 + 5;

#define lsb(s) (s & -(s))

template <typename T>
struct ftw{
	int n; T bits[mxN];

	ftw(int _n){
		this -> n = _n;
	}

	void add(int pos, T val){
		while(pos <= n){
			bits[pos] += val;
			pos += lsb(pos);
		}
	}
	T qry(int pos){
		T res = 0;
		while(pos > 0){
			res += bits[pos];
			pos -= lsb(pos);
		}
		return res;
	}
	T qry(int l, int r){
		return qry(r) - qry(l - 1);
	}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a[] = {1,2,3,4,5,6,7};
	ftw<ll> ft(7);
	int	n = 7;
	for(int i = 0; i < n; ++i){
		ft.add(i + 1, a[i]);
	}
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j)
			printf("sum of range [%d...%d] is: %lld\n", i, j, ft.qry(i + 1, j + 1));
}
