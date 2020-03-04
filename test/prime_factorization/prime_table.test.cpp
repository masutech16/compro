#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_1_C"
#include <iostream>
#include "../../lib/math/prime_factorization/prime_table.hpp"

int main() {
  std::vector<bool> isPrime = prime_table(100000000);
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    if (isPrime[a])
      ans++;
  }
  std::cout << ans << std::endl;
  return 0;
}
