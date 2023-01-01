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
const ll llinf = 1ll << 60;


struct graph {
	vector<vector<ll>> adj; int n; 
	graph(int _n) : adj(_n,vector<ll>(_n,llinf)), n(_n) { }

	void add_edge(int u, int v, ll w) { adj[u][v] = min(w,adj[u][v]); adj[v][u] = min(w,adj[v][u]); }
			
	void dijkstra(int u,vector<ll>& dist) {
		dist = vector<ll>(n, llinf); //results
		vector<ll> minArray(n,llinf); // minArray heap, contains the shortest distance between processed set and i
		vector<bool> visited(n,false);

		minArray[u] = 0;
		while (true) {
			auto curr = min_element(minArray.begin(),minArray.end()); 
			int u = distance(minArray.begin(), curr); ll w = *curr;
			if (w >= llinf) { break; } *curr = llinf;
			if (visited[u]) {continue;}
			visited[u] = true;
			dist[u] = min(llinf, w);

			for (int i = 0; i < n;i++){if (!visited[i]) { minArray[i] = min({ dist[u] + adj[u][i],minArray[i]}); }}
		}
	}

	void APSP(vector<vector<ll>>& dist) {
		dist = vector<vector<ll>>(n, vector<ll>(n));
		for (int i = 0; i < n; i++) { dijkstra(i, dist[i]); }
	}
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m,q;cin>>n>>m>>q;
	graph carte(n);
	for(int i=0;i<m;i++){
		ll u, v, w; cin >> u >> v >> w;
		carte.add_edge(--u, --v, w);
	}

	vector<vector<ll>>dist;
	carte.APSP(dist);

	int x, y;
	while (q--) { cin >> x >> y; --x; --y; cout << (dist[x][y] >= llinf ? -1 : dist[x][y]) << '\n'; }
	return 0;
}

