#include <iostream>
#include <vector>
#ifndef UNION_FIND
#define UNION_FIND
class UnionFind {
private:
  std::vector<int> parent;
  std::vector<int> _size;

  int root(int x) {
    if (parent[x] == -1)
      return x;
    return parent[x] = root(parent[x]);
  }

public:
  UnionFind(const int s) {
    parent = std::vector<int>(s, -1);
    _size = std::vector<int>(s, 1);
  }

  void merge(int x, int y) {
    int rx = root(x), ry = root(y);
    if (rx == ry)
      return;
    if (_size[rx] < _size[ry])
      std::swap(rx, ry);
    parent[ry] = rx;
    _size[rx] += _size[ry];
    _size[ry] = _size[rx];
  }

  int size(int x) { return _size[x]; }

  bool isSame(int x, int y) { return root(x) == root(y); }
};
#endif
