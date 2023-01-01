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
#include <iterator>
#include <functional>
#include <uchar.h>
#include <stdio.h>
using namespace std;
typedef long long ll;
const ll inf = 1ll << 60;

bool feasible(const vector<int> &arr,int d,ll c, int k) {
	ll coins = 0; int left = d;
	for (auto ptr = arr.rbegin(); ptr != arr.rend(); ptr++) {
		if (left == 0) { break; }
		int l = (d-(ptr-arr.rbegin())+k) / (k + 1);
		left -= l; coins += ll(*ptr) * ll(l);
	}
	return coins >= c;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int t; cin >> t; while (t--) {
		ll n, c, d; cin >> n >> c >> d;
		vector<int> arr(n); for (auto& e : arr) { cin >> e; }
		sort(arr.begin(), arr.end());

		int l = 0, r = d + 5;
		while (l < r) {
			int mid = (l + r + 1) / 2;
			if (feasible(arr, d, c, mid))  l = mid;
			else r = mid -1;
		}
		if ((l >= d) &&feasible(arr,d,c,l)) { cout << "Infinity" << '\n'; continue; }
		if (l == 0 && !feasible(arr, d, c, l)) { cout << "Impossible" << '\n'; continue; }
		cout << l << '\n';

	}

	return 0;
}


