#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
typedef long long ll;

int main() {
	ll n, t,dist=0;
	vector<ll> v;
	cin >> n;
	for (auto i = 0;i < n;i++) { cin >> t;v.push_back(t); }
	sort(v.begin(), v.end());
	t = -1;
	for (auto it = v.begin(); it < v.end(); it++) {
		if (t != *it) { dist++; }
		t = *it;
	}
	cout << dist << endl;

	return 0;
}
