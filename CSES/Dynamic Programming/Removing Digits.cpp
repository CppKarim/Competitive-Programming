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



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n;cin >> n;
	vector<int>dp(max(10,n + 1), 0);generate(next(dp.begin(),1), next(dp.begin(), 10), [] {return 1;});
	for (int i = 10;i < n + 1;i++) {
		for (int digit = i;digit > 0;digit /= 10) {
			if (digit % 10 == 0) { continue; }
			int move = dp[i - (digit % 10)];
			dp[i] = min(move, dp[i] > 0 ? dp[i] : move);
		}
		dp[i]++;
	}
	cout << dp[n] << '\n';
	return 0;
}


