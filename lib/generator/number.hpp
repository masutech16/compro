#include <vector>

#include "utils/random.hpp"

#ifndef COMPRO_GENERATOR_NUMBER
#define COMPRO_GENERATOR_NUMBER
template <class T> class NumberGenerator {
private:
  std::mt19937 mt;

public:
  NumberGenerator<T>() { mt = make_mt(); }

  // [lower_limit, upper_limit)の範囲で浮動小数点型の数を生成します。
  T gen(T lower_limit, T upper_limit) {
    std::uniform_real_distribution<T> dist(lower_limit, upper_limit);
    return dist(mt);
  }

  //  [lower_limit, upper_limit)の範囲の要素を持つsize個の浮動小数点型の数列を生成します。
  std::vector<T> gen_sequence(int size, T lower_limit, T upper_limit) {
    std::uniform_real_distribution<T> dist(lower_limit, upper_limit);
    std::vector<T> ret(size);
    for (int i = 0; i < size; i++) {
      ret[i] = dist(mt);
    }
    return ret;
  }
};
#endif
