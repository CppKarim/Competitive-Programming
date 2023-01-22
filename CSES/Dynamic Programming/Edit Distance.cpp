
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
const ll inf = 1ll << 60;



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string n, m;cin >> n >> m;
	vector<vector<int>> DP(n.size() + 1, vector<int>(m.size() + 1, 0));iota(DP[0].begin(), DP[0].end(), 0);

	for (int i = 1;i < n.size()+1;i++) {
		DP[i][0] = DP[i - 1][0] + 1;
		for (int j = 1;j < m.size()+1;j++) {
			DP[i][j] = min({1+DP[i-1][j],1+DP[i][j-1],DP[i-1][j-1]+(n[i-1]!=m[j-1])});
		}
	}
	cout << DP[n.size()][m.size()] << '\n';

	return 0;
}

