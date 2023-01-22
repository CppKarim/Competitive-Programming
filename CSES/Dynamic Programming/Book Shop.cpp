#include <fstream>
#include <iostream>
#include <utility>
#include <vector>
#include <numeric>
#include <algorithm>
#include <iterator>
#include <functional>

// inefficient solution: O(2^(#books)) +checking each for price and number of pages, produce the power set of the set of books.
// effecient solution: modify subset sum with no repetition to count #pages, O(nx).


int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0), std::cout.tie(0);
	
	int n, x;std::cin >> n >> x;
	std::vector<std::pair<short,short>>book(n);for (int i = 0;i < n;i++) { int in;std::cin >> in;book[i].first = in; }for (int i = 0;i < n;i++) { int in;std::cin >> in;book[i].second = in; }
	

	std::vector<int> dp(x + 1, 0);
	for (int j = 1;j < n + 1;j++) {
		std::vector<int>dpt = dp;
		for (int i = 1;i < x + 1;i++) {
			if (i - book[j - 1].first < 0) { continue; }
			dpt[i] = std::max(dp[i], dp[i - book[j - 1].first] + book[j - 1].second);
		}
		dp = std::move(dpt);
	}
	std::cout << dp[x] << '\n';
	return 0;
}


