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
	
	int n;cin >> n;ll sum = 0;
	vector<int>x(n);for (int i = 0;i < n;i++) { int in;cin >> in;x[i] = in;sum += in; }
	sort(x.begin(), x.end());

	ll mSum = 1;
	for (int i = 0;i < n;i++) {
		if (x[i] <= mSum) { mSum = mSum + x[i]; }
		else { break; }
	}
	cout << mSum << '\n';


	return 0;
}


