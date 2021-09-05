#include <iostream>
#include <vector>
#ifndef UNION_FIND
#define UNION_FIND
class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> size;

public:
  UnionFind(const int s) {
    parent = std::vector<int>(s, -1);
    size = std::vector<int>(s, 1);
  }

  void merge(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry)
      return;
    if (size[rx] < size[ry])
      std::swap(rx, ry);
    parent[ry] = rx;
    size[rx] += size[ry];
    size[ry] = size[rx];
  }

  int get_size(int x) { return size[root(x)]; }

  int root(int x) {
    if (parent[x] == -1)
      return x;
    return parent[x] = root(parent[x]);
  }

  bool is_same(int x, int y) { return root(x) == root(y); }
};
#endif
