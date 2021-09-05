#include <cassert>
#include <iostream>
#include <vector>
#ifndef WEIGHTED_UNION_FIND
#define WEIGHTED_UNION_FIND

// 重み付きUnionFind木
// 各ノードに重みを付けることができるUnionFind木。できる操作はUFでできることと同じで、各グループの重みの和が取れます。
template <class T> class WeightedUnionFind {
private:
  std::vector<int> parent;
  std::vector<int> size;
  std::vector<T> weight;

public:
  WeightedUnionFind(const int s, std::vector<T> weight) : weight(weight) {
    parent = std::vector<int>(s, -1);
    size = std::vector<int>(s, 1);
  }

  // x,yをマージする
  void merge(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry)
      return;
    if (size[rx] < size[ry])
      std::swap(rx, ry);
    parent[ry] = rx;
    size[rx] += size[ry];
    size[ry] = size[rx];
    weight[rx] += weight[ry];
    weight[ry] = weight[rx];
  }

  // xが所属しているグループの大きさを返す
  int get_size(int x) { return size[root(x)]; }

  // xが所属しているグループの重みの総和を返す
  T get_weight(int x) { return weight[root(x)]; }

  // xが所属しているグループの代表元を返す
  int root(int x) {
    if (parent[x] == -1)
      return x;
    return parent[x] = root(parent[x]);
  }

  // xとyが同じグループに所属しているかを判定する
  bool is_same(int x, int y) { return root(x) == root(y); }
};
#endif
