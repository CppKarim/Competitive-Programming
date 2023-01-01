#include <iostream>
#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int n, k; cin >> n >> k;
	indexed_set left; for (int i = 1; i <= n; i++) { left.insert(i); }
	int curr = -1;
	while (!left.empty()) {
		curr = (curr + k+1) % left.size();
		auto ptr = left.find_by_order(curr);
		cout << *ptr << ' '; left.erase(ptr); --curr;
	}

	return 0;
}