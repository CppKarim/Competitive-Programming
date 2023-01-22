
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


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	string s; cin >> s;
	int n = s.size();

	//Hashing
	ll prime = 12289;
	vector<ll> primePower(n, 1); for (int i = 1; i < n; i++) { primePower[i] = (primePower[i - 1] * prime) % mod; }
	vector<ll> prefHash(n, 0), sufHash(n,0);
	prefHash[0] = (s[0] * primePower[0]) % mod; for (int i = 1; i < n; i++) { prefHash[i] = (prefHash[i - 1] + s[i] * primePower[i]) % mod; }
	sufHash[n - 1] = (s[n - 1] * primePower[0]) % mod; for (int i = n - 2; i >= 0; i--) { sufHash[i] = (s[i]+sufHash[i+1]*prime) % mod; }
	for (int i = 0; i < n-1 ; i++) { if (prefHash[i] == sufHash[n-i-1]) { cout << i + 1 << ' '; } } cout << '\n';

	return 0;
}

 
