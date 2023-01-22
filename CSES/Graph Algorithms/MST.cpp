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
#include <set>
#include <map>
using namespace std;
typedef long long ll;

struct DSU {
	vector<int> rank, parent;

	DSU(int n) : rank(n, 1), parent(n) {
		iota(parent.begin(), parent.end(), 0);
	}

	int find(const int &u) { return parent[u] == u ? u : (parent[u] = find(parent[u])); }
	int size(int u) { return rank[find(u)]; }

	bool merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) { return false; }
		if (rank[u] < rank[v]) { swap(u, v); }
		rank[u] += rank[v];	parent[v] = u;
		return true;
	}
};

struct edge {
	int u, v; ll w;
	edge(int _u = 0, int _v = 0, ll _w = 1):u(_u),v(_v),w(_w) {}
	bool operator <(edge const e) const {
		return w < e.w;
	}
};

struct graph {
	vector<list<edge>> adj; int n; 
	graph(int _n) : adj(_n), n(_n) { }

	void add_edge(int u, int v, ll w) { adj[u].push_back({ u,v,w }); }
			
	void minSpanningTree(set<edge> &MST) {
		DSU group(n);
		set<edge> edges;
		for (auto& v : adj) { for (auto& e : v) { edges.emplace(e); } }
		for (auto& e : edges) {
			if (group.merge(e.u, e.v) ) { MST.emplace(e); }
		}

	}
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m;cin>>n>>m;
	graph carte(n);
	for(int i=0;i<m;i++){
		ll u, v, w; cin >> u >> v >> w;
		carte.add_edge(--u, --v, -w);
	}
	set<edge> MST; carte.minSpanningTree(MST);

	int score = 0; for (auto& e : MST) { score += e.w; }
	cout << -score << '\n';


}

