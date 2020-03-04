#include <vector>
#ifndef PRIME_FACTORIZATION
#define PRIME_FACTORIZATION

// nの素因数分解を行う。計算量O(sqrt(n))
std::vector<int> prime_factorization(int n) {
  std::vector<int> ret;
  for (int d = 2; d * d <= n; d++) {
    while (n % d == 0) {
      ret.push_back(d);
      n /= d;
    }
  }
  if (n != 1)
    ret.push_back(n);
  return ret;
}
#endif
