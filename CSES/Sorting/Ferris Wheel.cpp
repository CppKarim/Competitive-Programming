#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
typedef long long ll;
  
int main() {

	ll n, x,t,g=0,rem,s;
	cin >> n >> x;
	vector<ll> children; for (auto i = 0;i < n;i++) { cin >> t;children.push_back(t); }
	sort(children.begin(), children.end());
	auto right = children.end()-1;
	auto left = children.begin();
	while (left<right) {
		rem = x;s = 0;
		while (rem >= *right && right != left &&s < 2) { rem = rem - *right;right--;s++; }
		while (rem >= *left &&left != right&&s < 2) { rem = rem - *left; left++;s++; }
		if (s != 0) { g++; }
	}
	if (rem < *right||s == 2) { g++; }
	cout << g << endl;


	return 0;
}