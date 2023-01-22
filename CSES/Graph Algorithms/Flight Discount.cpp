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
	int u, v; ll w;
	edge(int u, int v, ll w) :u(u), v(v), w(w) {}
	const bool operator <(const edge v) const {
		return w < v.w;
	}
};
struct graph {
	vector<list<edge>> adj,adjR; int n;
	graph(int _n) : adj(_n),adjR(_n), n(_n) { }

	void add_edge(int u, int v, ll w) { adj[u].push_back({ u, v,w }); adjR[v].push_back({ v,u,w });}

	void dijkstra(int u, vector<ll>& dist,bool rev) {
		vector<list<edge>>* adjRef = rev ? &adjR : &adj;
		dist = vector<ll>(n, inf);
		priority_queue<pair<ll,int>, vector<pair<ll,int>>> heap; //{weight, node}
		vector<int> visited(n, 0);
		heap.push({0,u}); 
		while (!heap.empty()) {
			pair<ll,int> curr = heap.top(); heap.pop();
			if (visited[curr.second]) { continue; }
			visited[curr.second] = 1;
			dist[curr.second] = -curr.first;
			for (auto& e : (*adjRef)[curr.second]) {
				heap.push({-(dist[curr.second]+e.w),e.v});
			}
		}
	}

};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n, m; cin >> n >> m;
	graph carte(n);
	map<pair<int, int>, ll> connections;
	for (int i = 0; i < m; i++) {
		ll u; int v, w; cin >> u >> v >> w; u--; v--;
		carte.add_edge(u, v, w);
	}
	vector<ll>distS,distE;
	carte.dijkstra(0, distS,0); carte.dijkstra(n - 1, distE,1);
	ll cheapest = inf;
	for (int v = 0; v < n;v++) {
		for (auto &e : carte.adj[v]) {
			cheapest = min(cheapest, distS[e.u] + e.w / 2 + distE[e.v]);
		}
	}
	cout << cheapest << '\n';

	return 0;
}

