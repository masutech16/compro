#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_A"
#include <iostream>
#include "../../lib/math/prime_factorization/prime_factorization.hpp"

int main() {
  int n;
  std::cin >> n;
  std::vector<int> ans = prime_factorization(n);
  int m = ans.size();
  std::cout << n << ": ";
  for (int i = 0; i < m; i++) {
    std::cout << ans[i] << (i == m - 1 ? "\n" : " ");
  }
  return 0;
}
