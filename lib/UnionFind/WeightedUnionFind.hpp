#include <vector>

#include "Assert/Assert.hpp"

#ifndef WEIGHTED_UNION_FIND
#define WEIGHTED_UNION_FIND

// 重み付きUnionFind木
// 各ノードに重みを付けることができるUnionFind木。できる操作はUFでできることと同じで、各グループの重みの和が取れます。
template <class T> class WeightedUnionFind {
public:
  // s: 管理する集合の要素数
  // weight: 初期の重み。サイズがsである必要がある
  WeightedUnionFind(const int s, std::vector<T> weight) : s(s), weight(weight) {
    ASSERT_MSG(s == (int)weight.size(), "UFの管理するサイズと重さ配列の長さは一致している必要があります");
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
    weight[rx] += weight[ry];
    weight[ry] = weight[rx];
  }

  // xが所属しているグループの大きさを返す
  int get_size(int x) {
    check_range(x);
    return size[root(x)];
  }

  // xが所属しているグループの重みの総和を返す
  T get_weight(int x) {
    check_range(x);
    return weight[root(x)];
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
  std::vector<T> weight;
};
#endif
