#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <set>
using namespace std;
typedef long long ll;


int main() {
	//FILE *stream;
	//freopen_s(&stream,"test_input(7).txt", "r", stdin);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	multiset<int>price;
	for (int i = 0;i < n;i++) { int h; cin >> h; price.insert(h); }
	while (m--) {
		int t;cin >> t;
		auto ticket = price.upper_bound(t);
		if (ticket == price.begin()) { cout << -1 << '\n'; }
		else { cout << *(--ticket) << '\n'; price.erase(ticket); }

	}

	return 0;

}