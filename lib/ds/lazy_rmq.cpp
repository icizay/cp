#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

const int n = 1e6 + 5;
const ll INF = 1e18;
ll st[4 * n], lazy[4 * n];

void push(int cur, int l, int r){
	if(lazy[cur] == 0) return;
	st[cur] += lazy[cur];
	if(l != r){
		lazy[cur * 2] += lazy[cur];
		lazy[cur * 2 + 1] += lazy[cur];
	}
	lazy[cur] = 0;
}

void upd(int bl, int br, int cur = 1, int l = 0, int r = n - 1){
	push(cur, l, r);
	if(l > br || r < bl) return;
	if(bl <= l && r <= br){
		if(l != r){
			lazy[cur] += 1;
			push(cur, l, r);
		}else{
			st[cur] += 1;
		}
		return;
	}

	int mid = (l + r) / 2;
	upd(bl, br, cur * 2, l, mid);
	upd(bl, br, cur * 2 + 1, mid + 1, r);
	st[cur] = max(st[cur * 2], st[cur * 2 + 1]);
}

// r [bl..br] l

ll qry(int bl, int br, int cur = 1, int l = 0, int r = n - 1){
	push(cur, l, r);
	if(bl <= l && r <= br) return st[cur];
	if(l > br || r < bl) return -INF;
	int mid = (l + r) / 2;	
	return max(qry(bl, br, cur * 2, l, mid), qry(bl, br, cur * 2 + 1, mid + 1, r));
}


int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;
	while(q--){
		char t; int l, r; cin >> t >> l >> r;
		--l, --r;
		if(t == 'I') upd(l, r);
		else cout << qry(l, r) << "\n";
	}
}
