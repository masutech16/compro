#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_5_C"
#include "../../lib/math/modint.hpp"
#include <iostream>

using mint = ModInt<(int)1e9 + 7>;

int main() {
  int n, k;
  std::cin >> n >> k;
  if (n < k) {
    std::cout << 0 << std::endl;
    return 0;
  }

  std::vector<mint> table(k + 1);
  mint::combination_table(k, table);

  mint ans(0);
  for (int i = 0; i <= k; i++) {
    mint tmp = table[i] * mint::pow(mint(k - i), n);
    if (i % 2 == 0)
      ans += tmp;
    else
      ans -= tmp;
  }

  std::cout << ans << std::endl;
}
