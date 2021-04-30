#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define all(x) x.begin(), x.end()

#define lf (c << 1)
#define rg (c << 1) + 1
#define mi (l + (r - l) / 2)

const int N = 2e5 + 5;
struct node{
	ll v = 0, add = 0, set = 0;
} st[4 * N];

int n;

void push(int c, int l, int r){
	if(l == r){
		return;
	}
	if(st[c].set != 0){
		st[lf].set = st[rg].set = st[c].set;
		st[lf].v = (mi - l + 1) * st[c].set;
		st[rg].v = (r - mi) * st[c].set;
		st[lf].add = st[rg].add = 0;
		st[c].set = 0;
	}else if(st[c].add != 0){
		if(st[lf].set == 0) st[lf].add += st[c].add;
		else{
			st[lf].set += st[c].add;
			st[lf].add = 0;
		}
		if(st[rg].set == 0) st[rg].add += st[c].add;
		else{
			st[rg].set += st[c].add;
			st[rg].add = 0;
		}
		st[lf].v += (mi - l + 1) * st[c].add;
		st[rg].v += (r - mi) * st[c].add;
		st[c].add = 0;
	}
	return;
}

// r /= [bl...l...r...br] /= l

void inc_rng(int bl, int br, ll val, int c = 1, int l = 0, int r = n - 1){
	if(r < bl || l > br) return;
	push(c, l, r);
	if(bl <= l && r <= br){
		st[c].v += (r - l + 1) * val;
		if(st[c].set == 0) st[c].add += val;
		else st[c].set += val;
		return;
	}
	push(c, l, r);
	if(bl <= mi) inc_rng(bl, br, val, lf, l, mi);
	if(br > mi) inc_rng(bl, br, val, rg, mi + 1, r);
	st[c].v = st[lf].v + st[rg].v;
	return;
}

void set_rng(int bl, int br, ll val, int c = 1, int l = 0, int r = n - 1){
	if(r < bl || l > br) return;
	if(bl <= l && r <= br){
		st[c].v = (r - l + 1) * val;
		st[c].set = val;
		st[c].add = 0;
		return;
	}
	push(c, l, r);
	if(bl <= mi) set_rng(bl, br, val, lf, l, mi);
	if(br > mi) set_rng(bl, br, val, rg, mi + 1, r);
	st[c].v = st[lf].v + st[rg].v;
	return;
}

ll qry_rng(int bl, int br, int c = 1, int l = 0, int r = n - 1){
	if(r < bl || l > br) return 0;
	if(bl <= l && r <= br){
		return st[c].v;
	}
	push(c, l, r);
	ll ls = 0, rs = 0;
	if(bl <= mi) ls = qry_rng(bl, br, lf, l, mi);
	if(br > mi) rs = qry_rng(bl, br, rg, mi + 1, r);
	return ls + rs;
}

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int q; cin >> n >> q;
	for(int i = 0; i < n; ++i){
		ll x; cin >> x;
		set_rng(i, i, x);
	}
	while(q--){
		ll t, a, b, x; cin >> t;
		if(t == 1){
			cin >> a >> b >> x;
			--a, --b;
			inc_rng(a, b, x);
		}else if(t == 2){
			cin >> a >> b >> x;
			--a, --b;
			set_rng(a, b, x);
		}else{
			cin >> a >> b;
			--a, --b;
			ll aux = 0;
			aux = qry_rng(a, b);
			cout << aux << "\n";
		}
	}
}
