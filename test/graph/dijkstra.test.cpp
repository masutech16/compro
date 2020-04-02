#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_A&lang=jp"
#include "../../lib/graph/dijkstra.hpp"
#include <climits>
#include <iostream>
#include <vector>

int main() {
  int v, e, r;
  std::cin >> v >> e >> r;

  std::vector<std::vector<edge>> g(v);

  for (int i = 0; i < e; i++) {
    int s, t, d;
    std::cin >> s >> t >> d;
    g[s].push_back({t, d});
  }

  std::vector<int> ans(v);
  dijkstra(r, g, ans);

  for (int i = 0; i < v; i++) {
    if (ans[i] == INT_MAX) {
      std::cout << "INF" << std::endl;
    } else {
      std::cout << ans[i] << std::endl;
    }
  }
}
