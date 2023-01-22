#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <iterator>
#include <string>
using namespace std;
typedef long long ll;
  

int main() {
	ll g=0,n, m, k;cin >> n >> m >> k;

	ll t;vector<ll>tenant; for (auto i = 0;i < n;i++) { cin >> t; tenant.push_back(t); }
	vector<ll>flat;for (auto i = 0;i < m;i++) {	cin >> t;flat.push_back(t);}
	sort(flat.begin(), flat.end());sort(tenant.begin(), tenant.end());

	for (auto pers = tenant.begin(),apr=flat.begin();pers < tenant.end()&&apr<flat.end();pers++) {
		while (apr!=flat.end() && *apr < *pers - k) { apr++; }
		if (apr == flat.end()) { break; };
		if (*apr > *pers + k) { continue; }
		g++;apr++;
	}
	cout << g << endl;

	return 0;
}
