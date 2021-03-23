#include <cassert>
#include <iostream>
#include <vector>
#ifndef COMPRO_MATRIX
#define COMPRO_MATRIX

// 一点更新、一点削除、k番目に小さい値の取得ができるデータ構造を定義します

template <class T> class KthSmallest {
public:
  KthSmallest(int N) { data = std::vector<T>(N + 1, T(0)); }

  // 0-indexでi番目の要素にvalを加える
  void add(int index, T val) {
    // 内部的には1-indexで扱いたいので1足す
    index++;
    int N = data.size();
    for (int i = index; i <= N; i += i & -i) {
      data[i] += val;
    }
  }

  // 1-indexで昇順に並べたときのk番目の要素を返す
  T kth(int k) const {
    int N = data.size();
    assert(1 <= k && k <= N);
    int x = 0;
    int init = 1;
    while (2 * init <= N) {
      init *= 2;
    }
    for (int i = init; i > 0; i /= 2) {
      if (x + i <= N && data[x + i] < k) {
        k -= data[x + i];
        x += i;
      }
    }
    return x + 1;
  }

private:
  std::vector<T> data;
};

#endif
