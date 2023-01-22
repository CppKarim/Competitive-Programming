#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef long long ll;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& L, const StVal& R) { v = max(L , R); } //modify this operation for segment characteristic
	operator ll() const { return v; }
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;
	map<int, int> arri;


	SegTree(const int n) : n(n), leaves(n) { init(1, 0, n - 1); }

	void init(const int si, const int lo, const int hi) {
		if (lo == hi) {
			if (si >= (int)st.size()) st.resize(si + 1);
			st[si] = StVal(); leaves[lo] = si;
		}
		else {
			const int mid = (lo + hi) >> 1;
			init(si << 1, lo, mid);
			init(si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	bool isLeaf(int si) {
		if (arri.empty()) { for (int i = 0; i < n; i++) { arri[leaves[i]] = i; } }
		return (arri.find(si)!=arri.end());
	}

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	int indexQueryHelp(int val, int si) { 
		if (isLeaf(si)) {
			if (st[si].v >= val) {
				int i = arri[si];
				st[si].v -= val;
				update(i);
				return i;
			}
		}
		if (st[si].v < val) { return -1; } 
		return indexQueryHelp(val, (si << 1) + (st[si << 1].v < val ? 1 : 0));
	}
	int indexQuery(int val) {
		return indexQueryHelp(val, 1 );
	}

	//Modify According to Point Updates
	void update(const int i) {
		int si = leaves[i]; //st[si] is the point to update
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
	//Modify a value and then update
	void update(const int i, const int v) {
		int si = leaves[i];
		st[si] = v;
		update(i);
	}
};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	
	int n, m; cin >> n >> m;
	vector<int> hotel(n, 0), groups(m, 0); 
	for (auto& e : hotel) { cin >> e; }
	for (auto& e : groups) { cin >> e; }

	SegTree Q(n); for (int i = 0; i < n; i++) { Q.update(i, hotel[i]); }
	for (auto& e : groups) { cout << Q.indexQuery(e)+1<<' '; }cout << '\n';

}
