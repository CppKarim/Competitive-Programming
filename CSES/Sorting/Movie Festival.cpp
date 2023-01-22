#include <fstream>
#include <iostream>
#include <utility>
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>
#include <string>
#include <cmath>
#include <unordered_set>
#include <set>
#include <map>
#include<iterator>
#include <functional>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

void Solve(map<int, int> &movies, map<int, int>&shortest, int i) {
	auto el = movies.find(i);
	while (el != movies.begin()) {
		shortest[el->first] = max(shortest.upper_bound(el->first)->second, 1+shortest.lower_bound(el->second)->second);
		el--;
	}
		shortest[el->first] = max(shortest.upper_bound(el->first)->second, 1+shortest.lower_bound(el->second)->second);
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	//FILE *stream;
	//freopen_s(&stream,"tournament.in", "r", stdin);

	int n;cin >> n;
	map<int,int> movies;
	map<int, int> shortest;
	
	int lastStart=0;
	for (int i = 0;i < n;i++) {
		int a, b;cin >> a >> b; 
		movies[a]=max(movies[a],b);
		lastStart = max(lastStart, a);
	}
	for (auto i : movies) {
		if (i.second > lastStart) { shortest[i.second] = 0; }
	}
	Solve(movies, shortest,lastStart);
	cout << shortest.begin()->second << '\n';
	



	return 0;
}


