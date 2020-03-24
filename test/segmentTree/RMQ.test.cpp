#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A"
#include "../../lib/segment_tree.hpp"
#include <iostream>

int main() {
  int n, q;
  std::cin >> n >> q;
  SegmentTree<long long int> seg(
      n, (1LL << 31) - 1, [](long long int a, long long int b) -> long long int { return std::min(a, b); },
      [](long long int _, long long int b) -> long long int { return b; });
  for (int i = 0; i < q; i++) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0) {
      seg.update(x, y);
    } else {
      std::cout << seg.find(std::min(x, y), std::max(x, y) + 1) << std::endl;
    }
  }
}
