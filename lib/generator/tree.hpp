
#include <algorithm>

#include "integer.hpp"
#include "utils/random.hpp"

#ifndef COMPRO_GENERATOR_TREE
#define COMPRO_GENERATOR_TREE
class TreeGenerator {
private:
  std::mt19937 mt = make_mt();

public:
  // rootを根として頂点を{1,..., size}とした木を作ります。
  std::vector<std::pair<int, int>> gen(int size) {
    std::vector<int> parent(size, -1);
    IntegerGenerator<int> ig;
    for (int i = 1; i < size; i++) {
      parent[i] = ig.gen(1, i);
    }
    std::vector<std::pair<int, int>> ret;
    for (int i = 0; i < size; i++) {
      if (parent[i] == -1)
        continue;
      ret.push_back({i + 1, parent[i]});
    }
    return ret;
  }
};
#endif
