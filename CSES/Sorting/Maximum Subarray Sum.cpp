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
	vector<int>x(n);
	vector<ll>pref(n + 1);pref[0] = 0;
	for (int i = 0;i < n;i++) { int in;cin >> in;x[i] = in;pref[i + 1] = pref[i] + in; }
	vector<ll> cumMin(n + 1);ll minn = pref[0];
	for (int i = 0;i < n + 1;i++) {
		minn = min(minn, pref[i]);
		cumMin[i] = minn;
	}
	ll maxE = *max_element(x.begin(),x.end());

	ll maxSum = maxE;
	for (int i = 1;i < n + 1;i++) {
		maxSum = max(maxSum, pref[i] - cumMin[i-1]);
	}
	cout << maxSum << '\n';
	return 0;
}


