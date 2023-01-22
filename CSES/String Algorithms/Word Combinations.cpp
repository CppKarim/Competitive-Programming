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
#include <unordered_set>
#include <map>
using namespace std;
typedef long long ll;

ll mod = 1e9 + 7;

struct node {
	char v; bool present;map<char,node>children;
	node(char v='\0') :v(v),present(false) {}

	const bool operator <(const node e) const {
		return v<e.v;
	}
	const bool operator ==(const node e) const {
		return v==e.v;
	}
	void insert(string s) {
		if (!s.size()) { present=true; return; }
		char val = *s.rbegin(); s.pop_back();
		children[val].v = val; children[val].insert(s);
	}
};

struct trie {
	node root;

	trie() :root('\0') {}
	
	void addWord(string s) {
		reverse(s.begin(), s.end());
		root.insert(s);
	}
};


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	string s; cin >> s; int n = s.size();
	int k; cin >> k;
	trie dict; for (int i = 0; i < k; i++) { string e; cin >> e; dict.addWord(e); }

	vector<vector<bool>> doable(n + 1, vector<bool>(n + 1, false)); 
	for (int i = 0; i < n; i++) {
		node *curr = &dict.root;
		for (int j = i; j < n; j++) {
			auto finder = curr->children.find(s[j]);
			if (finder== curr->children.end()) {break;}
			curr = &(finder->second);
			if (curr->present) { doable[i][j] = true; }
		}
	}

	vector<int> pPrefix(n, 0);
	for (int i = 0; i < n; i++) {
		ll sSum = doable[0][i];
		for (int k = 0; k < i ; k++) { 
			sSum = (sSum+pPrefix[k] * doable[k + 1][i])%mod; }
		pPrefix[i] = sSum;
	}
	cout << pPrefix[n - 1] << '\n';


	return 0;
}

 