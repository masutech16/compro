#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A"
#include "../../lib/graph/bellman_ford.hpp"
#include <iostream>
#include <vector>

int main() {
  int v, e, r;
  std::cin >> v >> e >> r;

  std::vector<std::vector<edge<int>>> g(v);
  for (int i = 0; i < e; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g[s].push_back({t, d});
  }

  std::vector<int> d(v);
  auto is_negative = bellman_ford(r, g, d);

  if (is_negative) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
    return 0;
  }

  for (int i = 0; i < v; i++) {
    if (d[i] == std::numeric_limits<int>::max()) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << d[i] << std::endl;
    }
  }
}
