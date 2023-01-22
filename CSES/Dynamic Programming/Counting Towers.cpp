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
const int MOD = 1e9 + 7;

ll power(ll x, ll n) {
	ll res = 1;
	for (;n;n >>= 1, x = (x*x) % MOD) 
		if (n & 1) res = (res*x) % MOD;
	return res;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	vector<pair<ll, ll>> DP(10e6 + 1, { 0,0 });
	DP[1] = {1,1};
	int highest =1;
	int t;cin >> t;while (t--) {
		int n;cin >> n;
		while (highest < n) {
			highest++;
			DP[highest] = { (4 * DP[highest - 1].first + DP[highest - 1].second) % MOD,(DP[highest - 1].first + 2 * DP[highest - 1].second) % MOD };
		}
		cout << (DP[n].first+DP[n].second) % MOD << '\n';
	}
	return 0;
}


