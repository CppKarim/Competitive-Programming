#include <iostream>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>
#include <stdio.h>

#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <unordered_set>
#include <map>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

ll power(ll x, ll n, ll mod) {
	ll res = 1;
	for (; n; n >>= 1, x = (x * x) % mod)
		if (n & 1) res = (res * x) % mod;
	return res;
}

ll modInv(ll x) {
	return power(x, mod - 2, mod);
}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);


	string n, m; cin >> n >> m;
	int s = n.size(), l = m.size();
	if (l > s) { cout << 0 << '\n'; return 0; }


	vector<ll> hashedN(s, 0), cumlHashN(s + 1, 0); ll patternHash=0;
	ll prime = 12289;
	vector<ll> primePower(s, 1); for (int i = 1; i < s; i++) { primePower[i] = primePower[i - 1] * prime % mod; }
	for (int i = 0; i < l; i++) { patternHash =(patternHash+ static_cast<int>(m[i]) * primePower[i])%mod; }
	for (int i = 0; i < s; i++) { hashedN[i] = (static_cast<int>(n[i]) * primePower[i]) % mod; cumlHashN[i + 1] = (cumlHashN[i] + hashedN[i]) % mod; }

	int occ = 0;
	for (int i = 0; i + l < s+1; i++) {
		if((((cumlHashN[i + l] - cumlHashN[i]+mod) % mod) * modInv(primePower[i])) % mod == patternHash) occ++;
	}
	cout << occ << '\n';

	return 0;
}

 
