#include <climits>
#include <limits>
#include <queue>
#include <vector>

#ifndef DIJKSTRA
#define DIJKSTRA

template <class T> struct edge {
  int to;
  T cost;
};

// sからの各頂点への最短距離をdに格納して返す。計算量はO(E logV)
template <class T> void dijkstra(const int s, const std::vector<std::vector<edge<T>>> &g, std::vector<T> &d) {
  std::priority_queue<std::pair<T, int>, std::vector<std::pair<T, int>>, std::greater<std::pair<T, int>>> q;

  constexpr T MAX = std::numeric_limits<T>::max();

  for (auto &di : d) {
    di = MAX;
  }
  d[s] = 0;
  q.push(std::make_pair(d[s], s));

  while (!q.empty()) {
    const auto p = q.top();
    q.pop();

    const int v = p.second;
    if (d[v] < p.first)
      continue;

    for (const auto e : g[v]) {
      const int u = e.to;
      const T next_cost = d[v] + e.cost;
      if (d[u] <= next_cost)
        continue;
      d[u] = next_cost;
      q.push(std::make_pair(d[u], u));
    }
  }
}

#endif
