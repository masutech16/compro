#ifndef BOTH_SIDES_CUSUM
#define BOTH_SIDES_CUSUM

#include <utility>
#include <vector>

#include "Assert/Assert.hpp"
#include "Cusum/Cusum.hpp"

// 特定の要素だけを除いたsumが取れる累積和です
template <class T, class F> class BothSidesCusum {
public:
  BothSidesCusum(const std::vector<T> &v, F &&f, T init_value = 0) : n(v.size()), f(std::forward<F>(f)) {
    // TODO: 無駄なのでイテレーターでいい感じに初期化できるようになりたい
    std::vector<T> rev(n);
    for (int i = 0; i < n; i++) {
      rev[i] = v[n - 1 - i];
    }

    cusum = Cusum(v, std::forward<F>(f), init_value);
    revCusum = Cusum(rev, std::forward<F>(f), init_value);
  }

  // i番目の要素を除いた計算結果を返す
  T get_sum_except_for(int i) const {
    ASSERT_MSG(0 <= i && i < n, "iはvの長さの範囲内である必要があります");
    return f(cusum.get(i), revCusum.get(n - 1 - i));
  }

private:
  int n;
  const F f;
  Cusum<T, F> cusum;
  Cusum<T, F> revCusum;
};

#endif
