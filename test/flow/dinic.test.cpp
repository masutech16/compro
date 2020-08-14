#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_6_A"
#include "../../lib/flow/dinic.hpp"
#include <iostream>

int main() {
  int v, e;
  std::cin >> v >> e;
  Dinic<int> dinic(v);
  for (int i = 0; i < e; i++) {
    int u, v, c;
    std::cin >> u >> v >> c;
    dinic.add_edge(u, v, c);
  }

  std::cout << dinic.calc(0, v - 1) << std::endl;

  return 0;
}
