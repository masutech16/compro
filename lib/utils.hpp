#include <algorithm>
#include <string>
#include <vector>

#ifndef COMPRO_UTILS
#define COMPRO_UTILS

int to_int(std::string s) { return std::atoi(s.c_str()); }

long long int to_ll(std::string s) { return std::atoll(s.c_str()); }

// 最大公約数を求める
template <class T> T gcd(T n, T m) { return n ? gcd(m % n, n) : m; }

// 最小公倍数を求める
template <class T> T lcm(T n, T m) {
  int g = gcd(n, m);
  return n * m / g;
}

template <class T> void unique(std::vector<T> v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
  return v;
}

#endif
