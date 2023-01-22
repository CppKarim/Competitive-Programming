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
	vector<list<int>> adj; int n; vector<int>team;
	graph(int _n) : adj(_n), n(_n),team(n,-1) { }

	void add_edge(int u, int v) { adj[u].push_back(v); adj[v].push_back(u); }

	bool color() {
		for (int i = 0; i < n; i++) {
			if (team[i] != -1) 	{continue;}
			team[i] = 1;
			stack<int> trav; trav.push(i);
			while(!trav.empty()){
				int curr=trav.top(); trav.pop();
				for(auto ptr=adj[curr].begin();ptr!=adj[curr].end();ptr++){
					if(team[*ptr]==-1){trav.push(*ptr);team[*ptr]=3-team[curr];}
					else if(team[*ptr]==team[curr]){return false;}
				}
			}	
		}
		return true;
	}
};




int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//Construct
	int n,m;cin>>n>>m;
	graph social(n);
	for(int i=0;i<m;i++){
		int u,v;cin>>u>>v;
		social.add_edge(--u,--v);
	}
	bool possible = social.color();
	if (possible) { for (auto& team : social.team) { cout << team << ' '; }cout << '\n'; }
	else { cout << "IMPOSSIBLE" << '\n'; }

	return 0;
}


