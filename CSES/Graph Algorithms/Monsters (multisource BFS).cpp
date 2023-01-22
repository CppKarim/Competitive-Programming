#include <iostream>
#include <utility>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>
#include <stdio.h>

#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <array>
#include <map>
using namespace std;
typedef long long ll;

array<int, 4> dx = { 1,0,-1,0 };
array<int, 4> dy = { 0,1,0,-1 };
array<char, 4> dc = { 'D','R','U','L' };
map<char, int> invi = { {'D',0}, {'R',1}, {'U',2}, {'L',3} };

void bfs(vector<char> grid, int n, int m, deque<char>& path) {
	vector<int>visited(n * m, 0);
	queue<pair<int, bool>> q;
	vector<char> backtrack(m*n,' ');
	pair<int, bool> source;
	for (int i = 0; i < n*m; i++) {
		if (grid[i] == '#') { visited[i] = -1; continue; }
		if (grid[i] == 'A') { source = { i,true }; visited[i] = 1; continue; }
		if (grid[i] == 'M') { q.push({ i ,false }); visited[i] = 2; }
	}
	int reached=-1;q.push(source); 
	while (!q.empty()) {
		pair<int, bool> curr = q.front(); q.pop();
		bool good = curr.second; int x = curr.first / m, y = curr.first % m;
		if (good &&(x == 0 || x == n - 1 || y == 0 || y == m - 1)) {reached = curr.first; break; }

		for (int i = 0; i < 4; i++) {
			int e = (x + dx[i]) * m + (y + dy[i]); 
			if (e<0 || e>=n * m) { continue; }
			if (visited[e] == 0 ) { q.push({ e,good }); visited[e] = 2 - good; backtrack[e] = dc[i]; }
		}
	}
	if (reached + 1) {
		while (reached!=source.first) {
			char back = backtrack[reached]; path.push_front(back);
			reached = reached - ((abs(invi[back] - 2) - 1) * m - abs(invi[back] - 1) + 1);
		}
		path.push_front(' ');
	}

}



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n,m;cin>>n>>m;
	vector<char> grid(n * m, ' ');
	for (auto& e : grid) { cin >> e; }

	deque<char> path;
	bfs(grid, n, m, path);
	if (path.empty()) { cout << "NO" << '\n'; }
	else {
		path.pop_front();
		cout << "YES" << '\n' << path.size() << '\n';
		while (!path.empty()) { cout << path.front(); path.pop_front(); }cout << '\n';
	}

	return 0;
}


