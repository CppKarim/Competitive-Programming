#include <fstream>
#include <iostream>
#include <utility>
#include <queue>
#include <stack>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <set>
#include <map>
#include <iterator>
#include <functional>
using namespace std;
typedef long long ll;
vector<int> dx = { 0, 0, 1, -1 }, dy = {1,-1,0,0};





int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m;cin >> n >> m;
	vector<vector<int>> grid(n, vector<int>(m, 0));vector<pair<int, int>>nodes;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < m;j++) {
			char in;cin >> in;
			if (in == '.') {grid[i][j] = 1; nodes.push_back({ i,j });}
		}
	}
	int rooms = 0;
	for ( auto x : nodes) {
		if (grid[x.first][x.second] == -1) { continue; }
		rooms++;
		stack<pair<int,int>> component;component.push(x);
		while (!component.empty()) {
			pair<int, int> curr = component.top();component.pop();grid[curr.first][curr.second] = -1;
			for (int i = 0;i < 4;i++){
				int l = curr.first + dx[i], p = curr.second + dy[i]; if (l < 0 || l >= n || p < 0 || p >= m) { continue; }
				if (grid[l][p] == 1) { grid[l][p] = -1;component.push({ l,p }); }
				} 
			}
		}

	cout << rooms << '\n';




	return 0;
}


