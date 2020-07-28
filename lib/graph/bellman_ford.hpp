#include "edge.hpp"
#include <cassert>
#include <limits>
#include <vector>

#ifndef BELLMANFORD
#define BELLMANFORD

// 負経路が存在する場合はtrue,そうでない場合はfalseを返す
// @param s   初期位置
// @param g   グラフ
// @param d   結果を格納するvector
template <typename T> bool bellman_ford(const int s, const std::vector<std::vector<edge<T>>> &g, std::vector<T> &d) {

  assert(s < static_cast<int>(g.size()));
  assert(d.size() >= g.size());

  {
    int size = static_cast<int>(d.size());
    for (auto &el : d) {
      el = std::numeric_limits<T>::max();
    }
  }

  d[s] = 0;

  int counter = 0;
  while (true) {
    counter++;
    bool update = false;
    int size = g.size();
    for (int i = 0; i < size; i++) {
      for (const auto &e : g[i]) {
        if (d[i] != std::numeric_limits<T>::max() && d[e.to] > d[i] + e.cost) {
          d[e.to] = d[i] + e.cost;
          update = true;
        }
      }
    }
    if (!update) {
      break;
    }
    if (update && counter >= size) {
      return true;
    }
  }
  return false;
}

#endif
