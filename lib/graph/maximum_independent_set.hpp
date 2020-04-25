#include <algorithm>
#include <chrono>
#include <random>
#include <vector>

#ifndef MAXIMUM_INDEPENDENT_SET
#define MAXIMUM_INDEPENDENT_SET
std::mt19937 make_mt() { return std::mt19937(std::chrono::steady_clock::now().time_since_epoch().count()); }

std::vector<int> maximum_independent_set(const std::vector<std::vector<int>> matrix, int loop = 100000) {
  int size = matrix.size();
  std::vector<long long int> adjacents(size, 0LL);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {
      if (matrix[i][j] == 1) {
        adjacents[i] |= (1LL << j);
        adjacents[j] |= (1LL << i);
      }
    }
  }

  auto mt = make_mt();
  long long int max_vertices = 0LL;
  std::vector<int> vertices(size);
  std::iota(std::begin(vertices), std::end(vertices), 0);

  for (int num = 0; num < loop; num++) {
    std::shuffle(std::begin(vertices), std::end(vertices), mt);
    long long int current_vertices = 0LL;

    for (const auto v : vertices) {
      if ((current_vertices & adjacents[v]) != 0)
        continue;
      current_vertices |= (1LL << v);
    }

    if (__builtin_popcountll(max_vertices) < __builtin_popcountll(current_vertices))
      max_vertices = current_vertices;
  }

  std::vector<int> ans;
  for (int i = 0; i < size; i++) {
    if ((max_vertices >> i) % 2 == 1)
      ans.push_back(i);
  }
  return ans;
}
#endif
