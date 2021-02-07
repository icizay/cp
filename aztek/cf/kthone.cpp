#include <bits/stdc++.h>
using namespace std;

int64_t INF = 1000000000;

struct node{
    int64_t val, ind, sum;
};

int n;
const int N = 1e6;
node st[4 * N];
int64_t a[N];

void upd(int pos, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur].val ^= 1;
	st[cur].sum = (st[cur].val == 1);
	return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, cur * 2, l, mid);
    else
	upd(pos, cur * 2 + 1, mid + 1, r);
    st[cur].sum = st[cur * 2].sum + st[cur * 2 + 1].sum;
}

void build(int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = {a[l], l, a[l]};
	return;
    }
    int mid = (l + r) / 2;
    build(2 * cur, l, mid);
    build(2 * cur + 1, mid + 1, r);
    st[cur].sum = st[cur * 2].sum + st[cur * 2 + 1].sum;
}

int find(int k, int cur = 1, int l = 0, int r = n - 1){
    if(l == r) return cur;
    int mid = (l + r) / 2;
    if(st[cur].sum == k){
	if(st[2 * cur].sum < k) return find(k - st[2 * cur].sum, 2 * cur + 1, mid + 1, r);
	else if(st[2 * cur + 1].sum < k) return find(k, 2 * cur, l, mid);
    }else if(st[2*cur].sum < k)
	return find(k - st[2*cur].sum, 2 * cur + 1, mid + 1, r);
    return find(k, 2 * cur, l, mid);
}

void solve(){
    int m; cin >> n >> m;
    for(int i = 0; i < n; ++i){
	cin >> a[i];
    }

    build();

    for(int i = 0; i < m; ++i){
	int t, kek; cin >> t >> kek;
	if(t == 1){
	    upd(kek);
	}else{
	    int idx = find(kek + 1);
	    cout << st[idx].ind << "\n";
	}
    }

}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}

