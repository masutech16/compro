#include "../UnionFind/UnionFind.hpp"
#include "edge.hpp"
#include <algorithm>
#include <vector>
#ifndef KRUSKAL
#define KRUSKAL
template <class T> struct kruskal_edge {
  int from;
  int to;
  T cost;
};

// 最小全域木
template <class T> T kruskal(const std::vector<std::vector<edge<T>>> &graph) {
  const int size = graph.size();

  std::vector<kruskal_edge<T>> edges;
  for (int i = 0; i < size; i++) {
    for (const auto v : graph[i]) {
      if (v.to > i)
        continue;
      edges.push_back({i, v.to, v.cost});
    }
  }
  return kruskal(edges, size);
}

template <class T> T kruskal(std::vector<kruskal_edge<T>> edges, const int size) {
  T ret(0);
  std::sort(edges.begin(), edges.end(), [](kruskal_edge<T> a, kruskal_edge<T> b) { return a.cost < b.cost; });
  UnionFind uf(size);
  int edge_nums = 0;
  for (const auto e : edges) {
    if (uf.is_same(e.from, e.to))
      continue;
    uf.merge(e.from, e.to);
    edge_nums++;
    ret += e.cost;
  }
  return edge_nums == size - 1 ? ret : T(-1);
}
#endif
