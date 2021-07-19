constexpr int M = 1e9 + 7, N = 1e6;

template<int M>
struct Mint {
	int x;
	Mint(): x(0) { }
	Mint(int y) {
		x = y % M;
		if (x < 0) x += M;
	}
	Mint(long long y) {
		x = y % M;
		if (x < 0) x += M;
	}
	int get() const {return x;}
	bool operator==(const Mint &r) const {return x==r.x;}
	Mint &operator+=(const Mint &r) {if((x+=r.x)>=M) x-=M; return *this;}
	Mint &operator-=(const Mint &r) {if((x+=M-r.x)>=M) x-=M; return *this;}
	Mint &operator*=(const Mint &r) {x=(long long)x*r.x%M; return *this;}
	Mint &operator/=(const Mint &r) {x=(long long)x*r.inv().x%M; return *this;}
	Mint operator+(const Mint &r) const {return Mint(*this)+=r;}
	Mint operator-(const Mint &r) const {return Mint(*this)-=r;}
	Mint operator*(const Mint &r) const {return Mint(*this)*=r;}
	Mint operator/(const Mint &r) const {return Mint(*this)/=r;}
	Mint pow(int yy) const {
		Mint res(1), tt(x);
		while(yy){
			if(yy & 1) res *= tt;
			tt *= tt; 
			yy >>= 1;
		}
		return res;
	}
	Mint inv() const {
		int a = x, b = M, u = 1, v = 0;
		while(b) {
			int t = a / b;
			a -= t * b; swap(a, b);
			u -= t * v; swap(u, v);
		}
		if(u < 0) u += M;
		Mint res; res.x = (unsigned)u;
		return res;
	}
};

typedef Mint<M> mint;
mint F[N], F_inv[N];
bool r0 = 0;

void pc(){
	F[0] = F[1] = 1;
	for(int i = 2; i < N; ++i)
		F[i] = F[i - 1] * i;
	F_inv[N - 1] = Mint(F[N - 1]).inv();
	for(int i = N - 2; i >= 0; --i)
		F_inv[i] = F_inv[i + 1] * (i + 1);
	r0 ^= 1;
}

mint C(int n, int r){
	if(!r0) pc();
	if(r > n || r < 0) return 0;
	return F[n] * F_inv[n - r] * F_inv[r];
}

mint P(int n, int r){
	if(!r0) pc();
	if(r > n || r < 0) return 0; 
	return F[n] * F_inv[n - r];
}
