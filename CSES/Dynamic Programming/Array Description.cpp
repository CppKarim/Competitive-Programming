#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>
typedef long long ll;
const ll INF = 1ll << 60;
const int MOD = 1e9 + 7;



int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	
	int n, m;std::cin >> n >> m;
	std::vector<int> x(n);for (int i = 0;i < n;i++) { int in;std::cin >> in;x[i] = in; }
	
	std::vector<std::vector<int>> DP(n, std::vector<int>(m + 2, 0));
	DP[0][x[0]] = 1;
	if (x[0] == 0) { DP[0] = std::vector<int>(m + 2, 1);DP[0][0] = DP[0][m + 1] = 0; }

	for (int i = 1;i < n;i++) {
		int e = x[i];
		if (e == 0) { for (int j = 1;j < m + 1;j++) { DP[i][j] = ((DP[i - 1][j - 1] + DP[i - 1][j])%MOD + DP[i - 1][j + 1]) % MOD; } }
		else { DP[i][e] = ((DP[i - 1][e - 1] + DP[i - 1][e])%MOD + DP[i - 1][e + 1]) % MOD; }

	}
	ll ways = 0;for (int j = 1;j < m + 2;j++) { ways = (ways + DP[n - 1][j]) % MOD; }
	std::cout << ways << '\n';
	



	return 0;
}


