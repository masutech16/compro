#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_2_A"
#include "../../lib/graph/edge.hpp"
#include "../../lib/graph/kruskal.hpp"
#include <iostream>
#include <vector>

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<edge<int>>> graph(v);
  for (int i = 0; i < e; i++) {
    int s, t, w;
    std::cin >> s >> t >> w;
    graph[s].push_back({t, w});
    graph[t].push_back({s, w});
  }
  std::cout << kruskal(graph) << std::endl;
}
