
#include <algorithm>

#include "utils/random.hpp"

#ifndef COMPRO_GENERATOR_PERMUTATION
#define COMPRO_GENERATOR_PERMUTATION
class PermutationGenerator {
private:
  std::mt19937 mt = make_mt();

public:
  // {lower_limit, ..., upper_limit}の順列を生成します。
  std::vector<int> gen(int lower_limit, int upper_limit) {
    std::vector<int> ret(upper_limit - lower_limit + 1);
    for (int i = 0; i < upper_limit - lower_limit + 1; i++) {
      ret[i] = lower_limit + i;
    }
    std::shuffle(std::begin(ret), std::end(ret), mt);
    return ret;
  }
};
#endif
