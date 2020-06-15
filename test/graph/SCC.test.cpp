#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_3_C"
#include "../../lib/graph/SCC.hpp"
#include <iostream>
#include <vector>

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<int>> g(v);
  for (int i = 0; i < e; i++) {
    int u, v;
    std::cin >> u >> v;
    g[u].push_back(v);
  }

  SCC scc(g);

  int q;
  std::cin >> q;
  for (int i = 0; i < q; i++) {
    int u, v;
    std::cin >> u >> v;
    std::cout << (scc.get(u) == scc.get(v)) << std::endl;
  }
}
