#include <algorithm>
#include <vector>

#include <iostream>

template <typename T> struct edge {
  int to;
  T cost;
};

template <typename T>
std::vector<std::vector<T>>
warshallFloyd(const int size, const std::vector<std::vector<edge<T>>> &g,
              const T init) {

  std::vector<std::vector<T>> d(size);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (i == j) {
        d[i].push_back(0);
      } else {
        d[i].push_back(init);
      }
    }
  }

  for (int i = 0; i < size; i++) {
    for (const auto &e : g[i]) {
      d[i][e.to] = e.cost;
    }
  }

  for (int k = 0; k < size; k++) {
    for (int i = 0; i < size; i++) {
      for (int j = 0; j < size; j++) {
        if (d[i][k] != init && d[k][j] != init)
          d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
      }
    }
  }
  return d;
}

// verify: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/all/GRL_1_C
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
