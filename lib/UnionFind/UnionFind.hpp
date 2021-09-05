#include <vector>

#include "Assert/Assert.hpp"

#ifndef UNION_FIND
#define UNION_FIND

// UnionFind木です
// グループのマージ、取得が高速に行えます
class UnionFind {
public:
  // s: 管理する集合の要素数
  UnionFind(int s) : s(s) {
    parent = std::vector<int>(s, -1);
    size = std::vector<int>(s, 1);
  }

  // x,yをマージする
  void merge(int x, int y) {
    check_range(x);
    check_range(y);
    int rx = root(x), ry = root(y);
    if (rx == ry)
      return;
    if (size[rx] < size[ry])
      std::swap(rx, ry);
    parent[ry] = rx;
    size[rx] += size[ry];
    size[ry] = size[rx];
  }

  // xが所属しているグループの大きさを返す
  int get_size(int x) {
    check_range(x);
    return size[root(x)];
  }

  // xが所属しているグループの代表元を返す
  int root(int x) {
    check_range(x);
    if (parent[x] == -1)
      return x;
    return parent[x] = root(parent[x]);
  }

  // xとyが同じグループに所属しているかを判定する
  bool is_same(int x, int y) {
    check_range(x);
    check_range(y);
    return root(x) == root(y);
  }

private:
  // xがvalidな値かどうかを調べます
  void check_range(int x) { ASSERT_MSG(0 <= x && x < s, "引数で渡す値は0以上s未満である必要があります"); }

private:
  const int s;
  std::vector<int> parent;
  std::vector<int> size;
};
#endif
