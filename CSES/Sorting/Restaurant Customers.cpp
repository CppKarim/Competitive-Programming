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
	int n;
	cin >> n;
	map<int,int> customers;
	for(int i=0;i<n;i++){
		int a, b;cin >> a >> b;
		customers[a] = 1;customers[b] = -1;
	}

	int pref, maxx;pref = maxx = 0;
	for (auto it : customers) {
		pref = pref + it.second;
		maxx = max(maxx, pref);
	}
	cout << maxx << '\n';

	return 0;
}
