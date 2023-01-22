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
const ll MOD = 1000000007;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;cin >> n;
	vector<int> DP(n + 1, 0);DP[0]=DP[1] = 1;
	for (int i = 2;i < n+1;i++) {
		DP[i] =( (2*DP[i-1]-(i<7?0:(DP[i-7])))+MOD) % MOD;
	}
	cout << DP[n] << '\n';
	



	return 0;
}


