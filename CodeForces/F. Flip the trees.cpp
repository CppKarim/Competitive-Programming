#include <fstream>
#include <iostream>
#include <algorithm>
#include <cmath>	// abs
#include <ranges> // |std::views::reverse
#include <utility> //swap and tuples

#include <vector>
#include <list>
#include <queue>
#include <map>
using namespace std;
typedef long long ll;
const int intinf = 1 << 30;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& v1, const StVal& v2) { v = v1 + v2; } //modify this operation
	operator ll() const { return v; }
};

struct StUpdate {
	ll v = 0; StUpdate() {}
	StUpdate(const ll v) : v(v) {}
	StUpdate(const StUpdate& u1, const StUpdate& u2) { this->v = (u1.v ^ u2.v); } // and this one
	operator ll() const { return v; }
	void apply(StVal& v, const int lo, const int hi) {
		v.v = this->v ? (hi - lo + 1) - v.v : v.v;
	}
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<StUpdate> lazy;
	vector<int> leaves;

	SegTree(const int n) : n(n), leaves(n) {
		init(1, 0, n - 1); lazy.resize(st.size());
	}

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

	void updateLazy(const int si, const int lo, const int hi) {
		lazy[si].apply(st[si], lo, hi);
		if (lo != hi) {
			lazy[si << 1] = StUpdate(lazy[si << 1], lazy[si]);
			lazy[si << 1 | 1] = StUpdate(lazy[si << 1 | 1], lazy[si]);
		}
		lazy[si] = StUpdate();
	}

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	void update(const int l, const int r, const StUpdate u) { if (l <= r) update(l, r, u, 1, 0, n - 1); }
	void update(const int l, const int r, const StUpdate& u, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) {
			lazy[si] = StUpdate(lazy[si], u);
			updateLazy(si, lo, hi);
		}
		else {
			updateLazy(si, lo, hi);
			if (hi < l || r < lo) return;
			const int mid = (lo + hi) >> 1;
			update(l, r, u, si << 1, lo, mid);
			update(l, r, u, si << 1 | 1, mid + 1, hi);
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
		}
	}

	void update(const int i, const bool val) {
		int si = leaves[i];
		st[si] = StVal(val);
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}

	void updateAllLazy() { updateAllLazy(1, 0, n - 1); }
	void updateAllLazy(const int si, const int lo, const int hi) {
		updateLazy(si, lo, hi);
		if (lo != hi) {
			const int mid = (lo + hi) >> 1;
			updateAllLazy(si << 1, lo, mid);
			updateAllLazy(si << 1 | 1, mid + 1, hi);
		}
	}

	vector<StVal> retreive() {
		updateAllLazy();
		vector<StVal> res(n);
		for (int i = 0; i < n; ++i)
			res[i] = st[leaves[i]];
		return move(res);
	}
};

struct Tree {
	int n;
	vector<list<int>> tree;
	vector<int> start, finishTree, finishChildren, pos,color;
	Tree(const int n) : n(n), tree(n), start(n, -1), finishTree(n, -1), finishChildren(n, -1), pos(n, -1), color(n, 0) {}

	void preorder(int u, int& t) {
		start[u] = t;
		for (auto& x : tree[u]) {
			if (start[x] != -1) { continue; }
			pos[x] = t; t++;
		}
		finishChildren[u] = t - 1;
		for (auto& x : tree[u]) {
			if (start[x] != -1) { continue; }
			preorder(x, t);
		}
		finishTree[u] = t - 1;
	}

	void add_edge(int u, int v) {
		tree[u].push_back(v);
		tree[v].push_back(u);
	}

};

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	freopen("flip.in", "r", stdin);

	int t; cin >> t; while (t--) {
		int n, q; cin >> n >> q;
		Tree tree(n);
		SegTree st(n);

		for (int i = 0; i < n - 1; ++i) {
			int u, v; cin >> u >> v; u--; v--;
			tree.add_edge(u, v);
		}
		int t = 1;
		tree.pos[0] = 0;
		tree.preorder(0, t);

		for (int i = 0; i < q; ++i) {
			int type, node; cin >> type >> node; --node;
			if (type == 1) { st.update(tree.start[node], tree.finishChildren[node], 1); st.update(tree.pos[node], tree.pos[node], 1); tree.color[node] ^=1; }
			else { cout << st.query(tree.start[node], tree.finishTree[node]) + tree.color[node] << '\n'; }
		}
	}



	return 0;
}
