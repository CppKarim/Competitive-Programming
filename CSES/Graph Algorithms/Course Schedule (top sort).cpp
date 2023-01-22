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
using namespace std;
typedef long long ll;


struct graph {
	vector<vector<int>> adj; int n; 
	graph(int _n) : adj(_n), n(_n) { }

	void add_edge(int u, int v) { adj[u].push_back(v); }
	
	void DFShelp(int u, vector<int> &vis, vector<int>& start, vector<int>& end, int& time,bool &cycle) {
		vis[u] = 1; start[u] = time++;
		for (auto& e : adj[u]) {
			if (vis[e]&&end[e]==-1) cycle = true;
			if (cycle) { return; }
			if(!vis[e])DFShelp(e, vis, start, end, time,cycle);
			if (cycle) { return; }
		}
		end[u] = time++;
	
	}

	void DFS(int u, vector<int>& start, vector<int>& end,bool &cycle) {
		vector<int> vis(n,0); start = vector<int>(n, -1); end = vector<int>(n, -1);int time = 0; 
		for (int i = 0; i < n; i++) {
			if (!vis[i])DFShelp(i, vis, start, end, time,cycle);
		}

	}

	void topSort(vector<int>& sorted,bool &cycle) {
		vector<int> start, end;
		DFS(0,start, end,cycle);
		sorted = vector<int>(n); iota(sorted.begin(), sorted.end(), 0);
		sort(sorted.begin(), sorted.end(), [&](int &i, int &j) { return end[i] > end[j]; });
	}
		
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m;cin>>n>>m;
	graph map(n);
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		map.add_edge(--u,--v);
	}
	vector<int> sorted; bool cycle = false; map.topSort(sorted,cycle);
	if (!cycle) { for (auto& city : sorted) { cout << city + 1 << ' '; } } 
	else { cout << "IMPOSSIBLE\n"; }
	return 0;
}

 