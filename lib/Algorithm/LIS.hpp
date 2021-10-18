#ifndef COMPRO_LIS
#define COMPRO_LIS

#include <algorithm>
#include <vector>

// TODO: 復元機能を付ける

// LISについての便利機能を提供するクラスです
template <class T, class F> class LIS {
public:
  LIS(const std::vector<T> &v, F &&f) : v(v), f(std::forward<F>(f)) {}

  // 比較関数fによって得られるLis配列を構築します。計算量はO(NlogN)です
  // strictがtrueの場合、狭義単調増加でLisを構築します
  void build(bool strict = false) {
    int size = v.size();
    for (int i = 0; i < size; i++) {
      auto itr =
          strict ? std::upper_bound(begin(lis), end(lis), v[i], f) : std::lower_bound(begin(lis), end(lis), v[i], f);

      if (itr == std::end(lis)) {
        lis.emplace_back(v[i]);
      } else {
        *itr = v[i];
      }
    }
  }

  int size() const { return lis.size(); }

private:
  const std::vector<T> v;
  std::vector<T> lis;
  const F f;
};

#endif
