#include <iostream>
#include <utility>
#include <numeric>
#include <algorithm>
#include <string>
#include <iterator>
#include <functional>
#include <vector>
#include <set>
using namespace std;
typedef long long ll;
const ll INF = 1ll << 60;

struct StVal {
	ll v = 0; StVal() {}
	StVal(const ll _v) : v(_v) {}
	StVal(const StVal& L, const StVal& R) { v = max(L.v , R.v); } //modify this operation for segment characteristic
};

struct SegTree {
	int n;
	vector<StVal> st;
	vector<int> leaves;

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

	StVal query(const int l, const int r) { return (l <= r && l < n&& r >= 0) ? query(l, r, 1, 0, n - 1) : StVal(); }
	StVal query(const int l, const int r, const int si, const int lo, const int hi) {
		if (l <= lo && hi <= r) return st[si];

		const int mid = (lo + hi) >> 1;
		if (r <= mid) return query(l, r, si << 1, lo, mid);
		if (mid < l) return query(l, r, si << 1 | 1, mid + 1, hi);
		return StVal(query(l, r, si << 1, lo, mid), query(l, r, si << 1 | 1, mid + 1, hi));
	}

	//Modify According to Point Updates
	void update(const int i) {
		int si = leaves[i]; //st[si] is the point to update
		for (si >>= 1; si; si >>= 1)
			st[si] = StVal(st[si << 1], st[si << 1 | 1]);
	}
	//Modify a value and then update
	void update(const int i, const ll v) {
		int si = leaves[i];
		st[si] = v;
		update(i);
	
	}
};



int main() {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	int n;cin >> n;
	set<pair<int, int>> sorted;for (int i = 0;i < n;i++) { int in;cin >> in;sorted.emplace(in, i); }

	SegTree maxLIS(n);
	vector<pair<int, ll>>toUpdate;ll prev;bool first = true;
	for (auto e : sorted) {
		if (first) { first = false;toUpdate.push_back({ e.second, 1 });prev = e.first;continue; }
		if (e.first > prev) { while (!toUpdate.empty()) { auto q = toUpdate.back();toUpdate.pop_back(); maxLIS.update(q.first, q.second); } }
		auto dp = maxLIS.query(0, e.second - 1);
		toUpdate.push_back({ e.second,dp.v + 1 });
		prev = e.first;
	}while (!toUpdate.empty()) { auto q = toUpdate.back();toUpdate.pop_back(); maxLIS.update(q.first, q.second); }

	cout << maxLIS.query(0, n).v << '\n';

	return 0;
}


