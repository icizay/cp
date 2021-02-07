using namespace std;

const int N = 1e6;
int n;
int st[4 * N], a[N];

void upd(int pos, int val, int cur = 1, int l = 0, int r = n - 1){
    if(l == r){
	st[cur] = val;
	return;
    }

    int mid = (l + r) / 2;
    if(pos <= mid)
	upd(pos, val, cur * 2, l, mid);
    else
	upd(pos, val, cur * 2 + 1, mid + 1, r);
    st[cur] = min(st[cur * 2], st[cur * 2 + 1]);
}

int qry(int bl, int br, int cur = 1, int l = 0, int r = n - 1){
    if(bl <= l && r <= br) return st[cur];
    int mid = (l + r) / 2;
    return min(bl <= mid ? qry(bl, br, 2 * cur, l, mid) : (int)1e9, mid < br ? qry(bl, br, 2 * cur + 1, mid + 1, r) : (int)(1e9));
}

void solve(){
    int m;
    cin >> n >> m;
    for(int i = 0; i < n; ++i){
	cin >> a[i];
	upd(i, a[i]);
    }
    for(int i = 0; i < m; ++i){
	int t, x, y;
	cin >> t >> x >> y;
	if(t == 1){
	    upd(x, y);
	}else{
	    cout << qry(x, y) << "\n";
	}
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}


