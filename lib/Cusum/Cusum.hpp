#ifndef CUSUM
#define CUSUM

#include <vector>

#include "Assert/Assert.hpp"

// 1次元の累積和です
template <class T, class F> class Cusum {
public:
    Cusum() : n(0) {}

  // v: 累積和をとりたいベクトル
  // f: merge関数 f(cusum[i], v[i])と呼ばれる。
  Cusum(const std::vector<T> &v, F &&f, T init_value = T(0)) : n(v.size()) {
    cusum = std::vector<T>(n + 1);
    cusum[0] = init_value;
    for (int i = 0; i < n; i++) {
      cusum[i + 1] = f(cusum[i], v[i]);
    }
  }

  // v[0] op ... op v[i-1]の計算結果を返す
  T get(int i) const {
    ASSERT_MSG(0 <= i && i <= n, "iの値域が正しくありません");
    return cusum[i];
  }

private:
  int n;
  std::vector<T> cusum;
};

#endif
