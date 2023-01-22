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

	void BFS(int u,vector<int>&parent) {
		parent=vector<int>(n,-1);
		queue<int> q; q.push(u);
		while (!q.empty()) {
			int curr = q.front(); q.pop();
			for (auto ptr = adj[curr].begin(); ptr != adj[curr].end(); ptr++) {
				if (parent[*ptr]==-1&&*ptr!=0) { q.push(*ptr);parent[*ptr]=curr; }
			}
		}
	}
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//construct
	int n,m;cin>>n>>m;
	graph net(n);
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		net.add_edge(--u,--v);
	}
	//DFS
	vector<int> parent;
	net.BFS(0,parent);
	//Get path
	stack<int> path; int curr = n - 1; path.push(curr);
	while(parent[curr]!=-1){
		curr=parent[curr];
		path.push(curr);
	}
	if(path.top()!=0){cout<<"IMPOSSIBLE";}
	else { cout << path.size() << '\n'; while (!path.empty()) { cout << path.top() + 1 << ' '; path.pop(); } }

	return 0;
}


