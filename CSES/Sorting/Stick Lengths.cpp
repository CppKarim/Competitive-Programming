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
	vector<int> p(n) ;for (int i = 0;i < n;i++) { int in;cin >> in;p[i] = in; }
	sort(p.begin(), p.end());
	int x0 = (p.size() % 2 == 1) ? p[n / 2] : (p[n / 2] + p[n / 2 - 1]) / 2;

	ll cost=0;
	for (int i = 0;i < n;i++) { cost += abs(p[i] - x0); }
	cout << cost << '\n';


	return 0;
}


