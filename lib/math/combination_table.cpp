#include "./modint.cpp"
#include <vector>

// Tにはmintが来ることを期待している
// nCr mod MOD を r=0,...,n まで計算して埋めたテーブルを返す
template <class T> std::vector<T> combination_table(int n) {
  std::vector<T> vec(n + 1);
  vec[0] = T(0);
  for (int r = 1; r < n + 1; r++) {
    vec[r] = vec[r - 1] * T(n - r + 1) / T(r);
  }
  return vec;
}
