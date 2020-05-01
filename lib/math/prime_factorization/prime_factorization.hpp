#include <vector>
#ifndef PRIME_FACTORIZATION
#define PRIME_FACTORIZATION

// TODO: 一般化
// nの素因数分解を行う。計算量O(sqrt(n))
template <class T> std::vector<T> prime_factorization(T n) {
  std::vector<T> ret;
  for (T d = 2; d * d <= n; d++) {
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
