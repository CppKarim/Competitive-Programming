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
	int u;ll w;
	edge(int u, ll w) :u(u), w(w) {}
	const bool operator <(const edge v) const {
		return w < v.w;
	}
};

struct graph {
	vector<list<edge>> adj; int n; 
	graph(int _n) : adj(_n), n(_n) { }

	void add_edge(int u, int v, int w) { adj[u].push_back({ v,w }); }
		
	void dijkstra(int u,vector<ll>& dist) {
		dist = vector<ll>(n, inf); 
		priority_queue<edge, vector<edge>> heap; //{weight, node}
		set<int> visited; 
		heap.push({ u,0 });
		while ( ll(visited.size())!= n && !heap.empty()) {
			edge curr = heap.top(); heap.pop();
			if (visited.find(curr.u) != visited.end()) {continue;}
			visited.insert(curr.u);
			dist[curr.u] = min(inf, - curr.w);
			for (auto& e : adj[curr.u]) {
				if (visited.find(e.u) == visited.end()) {
					heap.push({ e.u, -(min(inf,dist[curr.u]+e.w)) });
				}
			}
		}
	}
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m;cin>>n>>m;
	graph carte(n);
	map<pair<int, int>, ll> connections;
	for(int i=0;i<m;i++){
		ll u, v, w; cin >> u >> v >> w; u--; v--; 
		if (connections.find({ u,v }) == connections.end()) { connections[{u, v}] = w; }
		else { connections[{u, v}] = min(connections[{u, v}], w); }
	}
	for (auto& e : connections) { carte.add_edge(e.first.first, e.first.second, e.second); }
	vector<ll>dist;
	carte.dijkstra(0, dist);
	for (auto& city : dist) { cout << city  << ' '; }
	return 0;
}

