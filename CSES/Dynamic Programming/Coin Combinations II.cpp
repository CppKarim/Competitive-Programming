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
const int MOD = 1000000007;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, x;cin >> n >> x;
	vector<int>c(n);for (int i = 0;i < n;i++) { int in;cin >> in;c[i] = in; }

	vector<int> DP(x + 1, 0);DP[0] = 1;
	for (int j = 0;j < n;j++) {
		for (int i = 1;i < x + 1;i++) {
			if (i - c[j] < 0) { continue; }
			DP[i] = (DP[i] + DP[i - c[j]]) % MOD;
		}
	}
	cout << DP[x] << '\n';

	return 0;
}


