#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_1_C&lang=jp"
#include <iostream>
#include "../../lib/graph/warshall_floyd.hpp"

int main() {
  int v, e;
  std::cin >> v >> e;
  std::vector<std::vector<edge<long long int>>> g(v);

  for (int i = 0; i < e; i++) {
    int a, b;
    long long int c;
    std::cin >> a >> b >> c;
    g[a].push_back({b, c});
  }

  long long int MAX = 200000000001;
  auto d = warshallFloyd(v, g, MAX);

  bool negative_cycle = false;
  for (int i = 0; i < v; i++) {
    if (d[i][i] < 0LL) {
      negative_cycle = true;
      break;
    }
  }

  if (negative_cycle) {
    std::cout << "NEGATIVE CYCLE" << std::endl;
  } else {
    for (int i = 0; i < v; i++) {
      for (int j = 0; j < v; j++) {
        if (d[i][j] == MAX) {
          std::cout << "INF";
        } else {
          std::cout << d[i][j];
        }
        std::cout << (j != v - 1 ? " " : "\n");
      }
    }
  }
}