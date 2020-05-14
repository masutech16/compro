#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_14_B"
#include "../../lib/rolling_hash.hpp"
#include <iostream>
#include <string>

int main() {
  std::string s, p;
  std::cin >> s >> p;
  RollingHash rhs(s);
  RollingHash rhp(p, rhs.get_base());

  int loop_num = s.length() - p.length() + 1;
  for (int i = 0; i < loop_num; i++) {
    if (rhs.get(i, i + p.length()) == rhp.get(0, p.length())) {
      std::cout << i << std::endl;
    }
  }
}
