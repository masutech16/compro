#include <chrono>
#include <random>
#include <vector>
#ifndef COMPRO_GENERATOR_INTEGER
#define COMPRO_GENERATOR_INTEGER
template <class T> class IntegerGenerator {
private:
  std::mt19937 mt;

public:
  IntegerGenerator<T>() { mt = std::mt19937((std::chrono::steady_clock::now().time_since_epoch().count())); }

  // [lower_limit, upper_limit]の範囲で整数を生成します。
  T gen(T lower_limit, T upper_limit) {
    std::uniform_int_distribution<T> dist(lower_limit, upper_limit);
    return dist(mt);
  }

  //  [lower_limit, upper_limit]の範囲の要素を持つsize個の整数列を生成します。
  std::vector<T> gen_sequence(int size, T lower_limit, T upper_limit) {
    std::uniform_int_distribution<T> dist(lower_limit, upper_limit);
    std::vector<T> ret(size);
    for (int i = 0; i < size; i++) {
      ret[i] = dist(mt);
    }
    return ret;
  }
};
#endif
