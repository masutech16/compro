#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C"
#include "../../lib/graph/LCA.hpp"
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<int> next(n, -1);
  for (int i = 0; i < n; i++) {
    int k;
    std::cin >> k;
    for (int j = 0; j < k; j++) {
      int c;
      std::cin >> c;
      next[c] = i;
    }
  }
  LCA lca(next);
  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << lca.get(u, v) << std::endl;
  }
}
