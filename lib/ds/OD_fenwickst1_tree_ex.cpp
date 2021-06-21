#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

const int mxN = 1e5 + 5;

template <typename T>
struct fwt{
	int n;
	T bits[mxN];

	fwt(int _n){
		this -> n = _n;
	}

	void add(int pos, T val){
		while(pos < n){
			bits[pos] += val;
			pos |= (pos + 1);
		}
	}

	T qry(int pos){
		T res = 0;
		while(pos >= 0){
			res += bits[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	T qry(int l, int r){
		return qry(r) - qry(l - 1);
	}
};

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int a[] = {1,2,3,4,5,6};
	fwt<ll> ft(6);
	int n = 6;
	for(int i = 0; i < 6; ++i){
		ft.add(i, a[i]);
	}
	for(int i = 0; i < n; ++i)
		for(int j = i; j < n; ++j){
			printf("sum of range a[%d...%d] is: %lld\n", i, j, ft.qry(i, j));
		}
}
