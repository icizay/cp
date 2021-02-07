#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> ans;
vector<int> row(10);
int x, y;

bool isok(int col){
    for(int i = 1; i < col; ++i)
	if(row[col] == row[i] || abs(row[col] - row[i]) == (col - i)) return false;
    return true;
}

void bt(int col){
    if(!isok(col-1)) return;
    if(col == y){
	bt(col + 1);
	return;
    }
    if(col == 9){
	ans.push_back(row);
	return;
    }

    for(int i = 1; i <= 8; ++i){
	row[col] = i;
	bt(col + 1);
    }
}

void solve(){
    cin >> x >> y;
    ans.clear();
    row[y] = x;

    bt(1);

    sort(ans.begin(), ans.end());

    printf("SOLN       COLUMN\n");
    printf(" #      1 2 3 4 5 6 7 8\n");
    printf("");

    for(int i = 0; i < ans.size(); ++i){
	printf("%2d      ", i + 1);
	for(int j = 1; j <= 7; ++j)
	    printf("%d ", ans[i][j]);
	printf("%d\n", ans[i][8]);
    }
}

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    int test; cin >> test;
    while(test--) solve();
}

