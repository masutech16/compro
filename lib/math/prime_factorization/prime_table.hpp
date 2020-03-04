#include <vector>
#ifndef PRIME_TABLE
#define PRIME_TABLE

// nまでの数が素数かどうかを判定できるvectorを返す. 計算量O(n sqrt(n))
std::vector<bool> prime_table(const int n) {
  int size = n + 1;
  std::vector<bool> table(size, true);
  table[0] = false;
  table[1] = false;
  for (int i = 2; i < size; i++) {
    if (!table[i])
      continue;
    for (int k = 2; i * k < size; k++) {
      table[i * k] = false;
    }
  }
  return table;
}
#endif
