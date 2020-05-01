#include <cmath>
#include <vector>

#ifndef DOUBLING
#define DOUBLING
// ダブリングを行う、最初の要素が入った配列を渡すとダブリングしたものを返す
// no_valueには存在しない場合何を入れればいいのかを入れておく
template <class T> std::vector<std::vector<T>> doubling(std::vector<T> &init, T no_value) {
  int size = init.size();
  int doubling_size = std::floor(std::log2(size) + 1);
  std::vector<std::vector<T>> ret(doubling_size, std::vector<T>(size));

  for (int i = 0; i < size; i++) {
    ret[0][i] = init[i];
  }

  for (int k = 0; k < doubling_size - 1; k++) {
    for (int i = 0; i < size; i++) {
      if (ret[k][i] == no_value) {
        ret[k + 1][i] = no_value;
      } else {
        ret[k + 1][i] = ret[k][ret[k][i]];
      }
    }
  }
  return ret;
}
#endif
