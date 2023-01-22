#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
using namespace std;
typedef long long ll;

pair<ll, ll> maxOminT(pair<ll, ll> p1, pair<ll, ll>p2) {
	if (p1.first != p2.first) { return max(p1, p2); }
	return min(p1, p2);

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	
	int n;cin >> n;
	vector<int> x(n);for (int i = 0;i < n;i++) { int in;cin >> in;x[i] = in; }
	
	vector<vector<pair<ll, ll>>>DP(n, vector < pair<ll, ll>>(n, { 0,0 }));
	for (int i = n - 1;i >= 0;i--) {
		for (int j = i;j < n;j++) {
			if (i == j) { DP[i][j] = { x[i],0 };continue; }
			DP[i][j] = maxOminT(pair<ll,ll>{x[j]+DP[i][j-1].second,DP[i][j-1].first},pair<ll,ll>{x[i]+DP[i+1][j].second,DP[i+1][j].first});
		}
	}
	cout << DP[0][n - 1].first << '\n';
	

	return 0;
}