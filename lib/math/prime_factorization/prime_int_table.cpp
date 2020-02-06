#include <vector>

#include <iostream>

// minFactor[i]: iを割り切る最小の素数。存在しない場合は-1。
std::vector<int> prime_int_table(const int n) {
  int size = n + 1;
  std::vector<int> table(size, -1);
  for (int i = 2; i < size; i++) {
    if (table[i] != -1)
      continue;
    table[i] = i;
    for (int k = 2; i * k < size; k++) {
      if (table[i * k] == -1) {
        table[i * k] = i;
      }
    }
  }
  return table;
}

// verify https://atcoder.jp/contests/abc052/tasks/arc067_a
int main() {
  int n;
  std::cin >> n;
  auto minFactor = prime_int_table(1000);
  std::vector<long long int> num(1001, 0LL);
  for (int i = 1; i <= n; i++) {
    int tmp = i;
    while (minFactor[tmp] != -1) {
      num[minFactor[tmp]]++;
      tmp /= minFactor[tmp];
    }
  }

  long long int ans = 1LL;
  for (int i = 0; i < (int)num.size(); i++) {
    ans *= num[i] + 1LL;
    ans %= 1000000007;
  }
  std::cout << ans << std::endl;
}
