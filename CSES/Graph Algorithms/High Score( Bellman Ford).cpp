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
	int u, v, w;
	edge(int u,int v, ll w) :u(u),v(v), w(w) {}
	const bool operator <(const edge v) const {
		return w < v.w;
	}
};

struct graph {
	int n; vector<list<edge>> adj, adjInv;
	graph(int _n) : n(_n), adj(_n), adjInv(_n) { }

	void add_edge(int u, int v, ll w) { adj[u].push_back({ u,v,w }); adjInv[v].push_back({ v,u,w }); }

	void BFS(int u, vector<bool> &vis, bool rev) {
		vector<list<edge>>* adjT = rev ? &adjInv : &adj;
		vis = vector<bool>(n, false);
		queue<int> q; q.push(u);
		
		vis[u] = true;
		while (!q.empty()) {
			int curr = q.front(); q.pop();

			for (auto& e : (*adjT)[curr])
				if (!vis[e.v]){ q.push(e.v); vis[e.v] = true;}
		}
	}
							
	void BellmaFord(int u,vector<ll>& dist) {
		dist = vector<ll>(n, inf); 
		
		dist[0] = 0;
		for (int i = 0; i < n; i++) {
			for (auto& u : adj) {for (auto& e : u) {
					dist[e.v] = min({ dist[e.v], dist[e.u] + e.w, inf });
				}}
		}
		//running inverse bfs on the last elements and checking if it can reach any affected nodes
		vector<bool> changed(n, false); 
		for (auto& u : adj) {for (auto& e : u) {
			changed[e.v] = changed[e.v]||(dist[e.v] >(dist[e.u] + e.w));
		}}
		vector<bool> fromFirst;
		vector<bool> toLast;
		BFS(0, fromFirst, 0);
		BFS(n-1, toLast, 1);
		for (int i = 0; i < n; i++) {
			if (fromFirst[i] && toLast[i] && changed[i]) { dist[n - 1] = 1; break; }
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
		int u, v;ll w; cin >> u >> v >> w;
		carte.add_edge(--u, --v, -w);
	}
	vector<ll>dist;
	carte.BellmaFord(0, dist);
	cout << -dist[n - 1] << '\n';
	return 0;
}

