#include <bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin >> n;
    cout << (n + 1) * (n + 1) / 2 - 1 << "\n";
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test; cin >> test;
    while(test--) solve();
}
