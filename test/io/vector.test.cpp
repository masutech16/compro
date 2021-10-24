#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_A"
#include "../../lib/IO/Vector.hpp"
#include <cmath>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<int> a(m);
  std::cin >> a;
  std::vector<int> dp(n + 1, 50001);
  dp[0] = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < m; j++) {
      if (i - a[j] >= 0) {
        dp[i] = std::min(dp[i], dp[i - a[j]] + 1);
      }
    }
  }

  std::cout << dp[n] << std::endl;
}
