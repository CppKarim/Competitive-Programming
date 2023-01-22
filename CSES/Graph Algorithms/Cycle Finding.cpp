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
const ll inf = 1ll << 60;

struct edge {
	int u, v;ll w;
	edge(int u,int v, ll w) :u(u),v(v), w(w) {}
	const bool operator <(const edge v) const {
		return w < v.w;
	}
};

struct graph {
	int n; vector<vector<edge>> adj, adjInv;
	graph(int _n) : n(_n), adj(_n), adjInv(_n) { }

	void add_edge(int u, int v, ll w) { adj[u].push_back({ u,v,w }); adjInv[v].push_back({ v,u,w }); }


	void BellmanFord(int u,vector<ll>& dist,vector<int> &cycle) {
		dist = vector<ll>(n, inf); vector<int> parent(n, -1);
		dist[0] = 0; parent[u] = u;
		for (int i = 0; i < n; i++) {
			for (auto& u : adj) {for (auto& e : u) {
				if (dist[e.u] + e.w < dist[e.v]) {
					dist[e.v] = dist[e.u] + e.w;
					parent[e.v] = e.u;
				}
			}}
		}
		int reacheable = -1;
		for (auto& u : adj) {for (auto& e : u) {
			if (dist[e.v] > dist[e.u] + e.w) {
				reacheable = e.v; break;
			}
			if ((reacheable + 1)) { break; }

		}}
		if (!(reacheable + 1)) { return; }

		
		vector<int> vis(n, 0);
		cycle.push_back(reacheable); vis[reacheable] = 1;
		int curr = parent[reacheable];
		while (!vis[curr]) {
			cycle.push_back(curr);
			vis[curr] = 1;
			curr = parent[curr];
		}cycle.push_back(curr);
		reverse(cycle.begin(), cycle.end());
		while (cycle[cycle.size()-1] != curr) { cycle.pop_back(); }


	}
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m;cin>>n>>m;
	graph carte(n);
	for(int i=0;i<m;i++){
		int u, v;ll w; cin >> u >> v >> w;
		carte.add_edge(--u, --v, w);
	}
	vector<ll>dist; vector<int> negCycle;
	carte.BellmanFord(0, dist,negCycle);
	cout << (negCycle.size() ? "YES" : "NO") << '\n';
	if (negCycle.size()) { for (auto& e : negCycle) { cout << e+1 << ' '; }cout << '\n'; }
	return 0;
}

