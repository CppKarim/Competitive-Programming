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
	int u,v;ll w;
	edge(int u, int v, ll w) :u(u), v(v), w(w) {}
	const bool operator <(const edge v) const {
		return w < v.w;
	}
};

struct graph {
	vector<list<edge>> adj; int n; 
	graph(int _n) : adj(_n), n(_n) { }

	void add_edge(int u, int v, ll w) { adj[u].push_back({ u,v,w }); }
		
	void dijkstra(int u,vector<vector<ll>>& dist,int k) {
		dist = vector<vector<ll>>(n); 
		priority_queue<pair<ll,int>, vector<pair<ll,int>>> heap; //{weight, node}
		heap.push({ 0,u });
		while (!heap.empty()) {
			pair<ll,int> curr = heap.top(); heap.pop();
			if (dist[curr.second].size()>=k) { continue; }
			dist[curr.second].push_back(-curr.first);
			for (auto& e : adj[curr.second]) {
					heap.push({ -(-curr.first + e.w),e.v });
				}
		}
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m,k;cin>>n>>m>>k;
	graph carte(n);
	for(int i=0;i<m;i++){
		int u, v;ll w; cin >> u >> v >> w;
		carte.add_edge(--u, --v, w);
	}
	vector<vector<ll>>dist; 
	carte.dijkstra(0, dist,k);
	for (auto& e : dist[n - 1]) { cout << e << ' '; }cout << '\n';
	
	return 0;
}

