#include <iostream>
#include <utility>
#include <vector>
#include <queue>
#include <numeric>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>
using namespace std;
typedef long long ll;

vector<int> dx = { 1,0,-1,0 }, dy = { 0,1,0,-1 }; vector<char>d = { 'D','R','U','L' };

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n,m;cin>>n>>m;
	vector<vector<char>> grid(n,vector<char>(m,'.'));
	vector<vector<int>> parent(n, vector<int>(m, -1));
	queue<pair<int,int>> q;
	for (int row = 0; row < n; row++) {for (int col = 0; col < m; col++) {cin >> grid[row][col]; if (grid[row][col] == 'A') { q.push({row,col}); }}}
	
	parent[q.front().first][q.front().second] = -2;
	pair<int, int>last;
	while (!q.empty()) {
		auto curr = q.front(); q.pop();
		int row = curr.first, col = curr.second;
		if (grid[row][col] == 'B') { last = curr; break; }
		for(int i=0;i<4;i++){
			int x=row+dx[i],y=col+dy[i];
			if (x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#' && parent[x][y] == -1) { q.push({ x,y }); parent[x][y] = i; }
		}
	}
	string path = "";
	while (parent[last.first][last.second]>=0) {
		int dir = parent[last.first][last.second];
		path += d[dir];
		last = { last.first - dx[dir],last.second - dy[dir] };
	}
	path = string(path.rbegin(), path.rend());

	cout << (path.length() == 0 ? "NO" : "YES") << "\n";
	if (path.length() != 0) { cout << path.length() << '\n' << path; }


	return 0;
}


