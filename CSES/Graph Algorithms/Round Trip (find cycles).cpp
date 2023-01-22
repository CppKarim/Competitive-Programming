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
	vector<list<int>> adj; int n; 
	graph(int _n) : adj(_n), n(_n) { }

	void add_edge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }
		
	deque<int> DFS() {
		vector<bool> visited(n, false), inStack(n, false); deque<int>cycle; bool done = false; int start=-1;
		for (int i = 0; i < n; i++) {
			if(!done && !visited[i]) DFSHelper(i,i, cycle, visited,inStack,done,start);
		}
		while (!cycle.empty() && cycle.front() != start) { cycle.pop_front(); }
		return cycle;
	}
	void DFSHelper(int u,int p, deque<int>& cycle, vector<bool>& visited, vector<bool>& inStack, bool& done,int&start) {
		cycle.push_back(u); visited[u] = true; inStack[u] = true;
		for (auto& e : adj[u]) {
			if (!visited[e]) DFSHelper(e,u, cycle,visited,inStack,done,start);
			else if (inStack[e] && e != p) { done = true; start = e; }
			if (done) return ;
		}
		cycle.pop_back(); inStack[u] = false;
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
	deque<int> cycle;
	cycle=map.DFS();
	bool possible = !cycle.empty();
	if (possible) { cout << cycle.size()+1 << '\n'; for (auto& city : cycle) { cout << city + 1 << ' '; }cout << cycle[0] + 1 << '\n'; }
	else { cout << "IMPOSSIBLE" << '\n'; }

	return 0;
}


