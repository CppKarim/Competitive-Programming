#include <fstream>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <set>
#include <map>
#include<iterator>
#include <functional>
using namespace std;
typedef long long ll;
const ll inf = 1ll << 60;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int a, b;cin >> a >> b;
	vector<vector<int>>DP(a + 1, vector<int>(b + 1, 0));
	for (int i = 1;i < a + 1;i++) { DP[i][1] = i - 1; }
	for (int j = 1;j < b + 1;j++) { DP[1][j] = j - 1; }

	for (int i = 2;i < a + 1;i++) {
		for (int j = 2;j < b + 1;j++) {
			if (i == j) { DP[i][j] = 0;continue; }
			int mRow = DP[i][1] + DP[i][j - 1], mCol = DP[1][j] + DP[i-1][j];
			for (int k = 1;k < j;k++) { mRow = min(mRow, DP[i][k]+DP[i][j-k]); }
			for (int l = 1;l < i;l++) { mCol = min(mCol, DP[l][j] + DP[i - l][j]); }
			DP[i][j] = 1 + min(mRow, mCol);
		}
	}
	cout << DP[a][b] << '\n';
	return 0;
}


