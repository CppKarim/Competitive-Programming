#include <fstream>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <list>
#include <numeric>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <set>
#include <map>
#include <iterator>
#include <functional>
#include <uchar.h>
#include <stdio.h>
using namespace std;
typedef long long ll;

struct graph {
	vector<list<int>> adj; int n; vector<int> rep;
	graph(int _n) : adj(_n), n(_n), rep(n,-1) { }

	void add_edge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }

	int BFS(int u) {
		if (rep[u] != -1) { return rep[u]; }
		queue<int> q; q.push(u);
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			rep[curr]=u;
			for (auto ptr = adj[curr].begin(); ptr != adj[curr].end(); ptr++) {
				if (rep[*ptr]==-1) { q.push(*ptr); }
			}
		}
		return rep[u];
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n, m; cin >> n >> m;
	graph map(n); set<int> conComp;
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		map.add_edge(u, v);
	}

	for(int i=0;i<n;i++){
		conComp.emplace(map.BFS(i));
	}
	
	cout << conComp.size() - 1 << '\n';
	for (auto ptr = conComp.begin(); next(ptr,1) != conComp.end(); ptr++) {
		cout << *ptr + 1 << ' ' << *(next(ptr, 1)) + 1 << '\n';
	}
	cout << "\b ";
	return 0;
}


