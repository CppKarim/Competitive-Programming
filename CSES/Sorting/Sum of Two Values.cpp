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

bool comp(pair<int, int> i1, pair<int, int>i2) { return i1 < i2; }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	

	int n, x; cin >> n >> x;
	multimap<int,int>index;
	for (int i = 1; i <= n;i++) {int in;cin >> in;index.emplace(in, i);}

	bool possible = false;
	for (auto e : index) {
		int t = x - e.first;
		auto res = index.find(t); if (x == 2 * t) { res++; }
		if (res == index.end()||res->first!=t) { continue; }
		cout << e.second << ' ' << res->second << '\n';
		possible = true;break;

	}
	if (!possible) { cout << "IMPOSSIBLE"<<'\n'; }

	return 0;
}


