#define PROBLEM "https://judge.yosupo.jp/problem/maximum_independent_set"
#include "../../lib/graph/maximum_independent_set.hpp"
#include <iostream>
#include <vector>

int main() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::vector<int>> mat(n, std::vector<int>(n, 0));
  for (int i = 0; i < m; i++) {
    int a, b;
    std::cin >> a >> b;
    mat[a][b] = mat[b][a] = 1;
  }
  auto ans = maximum_independent_set(mat);
  std::cout << ans.size() << std::endl;
  for (int i = 0, size = ans.size(); i < size; i++) {
    std::cout << ans[i] << (i == size - 1 ? "\n" : " ");
  }
}
