#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include<iterator>
#include <functional>
#include<set>
using namespace std;
typedef long long ll;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;cin >> n ;
	set<int> sums;for (int i = 0;i < n;i++) { int in;cin >> in;vector<int>temp;
	for (auto e : sums) { temp.push_back(e + in); };for (auto &e : temp) { sums.emplace(e); }sums.emplace(in);}
	cout << sums.size() << '\n';
	for (auto e : sums) { cout << e << ' '; }
	cout << '\n';

	return 0;
}


