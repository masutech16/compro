#include <algorithm>
#include <vector>

#ifndef WARSHALL_FLOYD
#define WARSHALL_FLOYD
#include "edge.hpp"

template <typename T>
std::vector<std::vector<T>> warshallFloyd(const int size, const std::vector<std::vector<edge<T>>> &g, const T init) {

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
#endif
