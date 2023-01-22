#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll power(ll x, ll n) {
	ll res = 1;
	for (;n;n >>= 1, x = (x*x) % MOD) 
		if (n & 1) res = (res*x) % MOD;
	return res;
}

const int modInv = power(2,MOD-2);

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;cin >> n;
	if ((n + 1)*n % 4 != 0) { cout << 0 << ' ';return 0; }

	vector<ll> DP(n*(n + 1) / 2 + 1, 0);DP[0] = 1;
	for (int j = 1;j < n + 1;j++) {
		for (int i = n*(n + 1) / 2;i >= j;i--) { DP[i] = (DP[i] + DP[i - j]) % MOD; }
	}
	cout << (DP[n*(n + 1) / 4] * modInv) % MOD << '\n';
	return 0;
}
