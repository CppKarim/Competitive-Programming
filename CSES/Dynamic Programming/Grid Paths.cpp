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
const ll INF = 1ll << 60;
const int MOD = 1e9 + 7;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;cin >> n;
	vector<vector<ll>>grid(n, vector<ll>(n, 0));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			char in;cin >> in;
			if (in == '*') { grid[i][j] = -1; }
		}
	}
	grid[n - 1][n - 1]++;
	for (int i = n - 1;i >= 0;i--) {
		for (int j = n - 1;j >= 0;j--) {
			if (grid[i][j] == -1|| (i==n-1&&j==n-1)) { continue; }
			grid[i][j] = (grid[i][j]+(j + 1 < n ? max(grid[i][j + 1], 0ll) : 0) + (i + 1 < n ? max(grid[i + 1][j], 0ll) : 0)) % MOD;
		}
	}
	cout << max(0ll,grid[0][0]) << '\n';
	return 0;
}


