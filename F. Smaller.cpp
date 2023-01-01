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
#include <unordered_map>
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
	
	int t;cin >> t;while (t--) {
		int q;cin >> q;
		vector<ll> s(27, 0), t(27, 0);s[0] = s[26] = 1;t[0] = t[26] = 1;
		for (int i = 0;i < q;i++) {
			int d, k;string x;cin >> d >> k;cin >> x;
			for (auto el : x) { if (d == 1) { s[el - 'a'] += k;s[26] += k; } else { t[el - 'a'] += k; t[26] += k; } }
			bool possible = (t[26] - t[0] != 0) || (t[26] - t[0] == 0 && s[26] - s[0] == 0 && s[0] < t[0]);
			cout << (possible ? "YES" : "NO") << '\n';
		}
	}
	

	return 0;
}


