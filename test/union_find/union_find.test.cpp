#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_1_A"
#include "../../lib/union_find.hpp"

int main() {
  int n, q;
  std::cin >> n >> q;
  UnionFind uf(n);

  for (int i = 0; i < q; i++) {
    int com, x, y;
    std::cin >> com >> x >> y;
    if (com == 0)
      uf.merge(x, y);
    else
      std::cout << (uf.isSame(x, y) ? 1 : 0) << std::endl;
  }
}
