#include <bits/stdc++.h>
using namespace std;

void solve(){
    int64_t dp[17][17][17];
    memset(dp, 0, sizeof(dp));
    dp[1][1][1] = 1;
    for(int i = 2; i <= 13; ++i)
	for(int j = 1; j <= i; ++j)
	    for(int k = 1; k <= i; ++k)
		dp[i][j][k] = dp[i - 1][j][k] * (i - 2) + dp[i - 1][j - 1][k] + dp[i-1][j][k - 1];		
    int t; cin >> t;
    while(t--){
	int a, b, c; cin >> a >> b >> c;
	cout << dp[a][b][c] << "\n";
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test = 1;
    while(test--) solve();
}
