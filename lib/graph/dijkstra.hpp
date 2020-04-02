#include <climits>
#include <queue>
#include <vector>

#ifndef DIJKSTRA
#define DIJKSTRA

// TODO: 抽象化する
struct edge {
  int to, cost;
};

// sからの各頂点への最短距離をdに格納して返す。計算量はO(E logV)
void dijkstra(const int s, const std::vector<std::vector<edge>> &g, std::vector<int> &d) {
  std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> q;

  for (auto &di : d) {
    di = INT_MAX;
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
      const int next_cost = d[v] + e.cost;
      if (d[u] <= next_cost)
        continue;
      d[u] = next_cost;
      q.push(std::make_pair(d[u], u));
    }
  }
}

#endif
