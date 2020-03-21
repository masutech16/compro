#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=NTL_1_B"
#include "../../lib/math/modint.hpp"
#include <iostream>

using mint = ModInt<1000000007>;

int main() {
  mint m;
  int n;
  std::cin >> m >> n;
  std::cout << mint::pow(m, n) << std::endl;
}
