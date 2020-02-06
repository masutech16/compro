#include <vector>

#include <iostream>

// nまでの数が素数かどうかを判定できるvectorを返す
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
  return isPrime;
}

// verify https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
int main() {
  std::vector<bool> isPrime = prime_table(10000);
  int n;
  std::cin >> n;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    std::cin >> a;
    bool flag = true;
    for (int j = 1; j < std::min(a, (int)isPrime.size()); j++) {
      if (!isPrime[j])
        continue;
      if (a % j == 0) {
        flag = false;
        break;
      }
    }
    if (flag)
      ans++;
  }
  std::cout << ans << std::endl;
  return 0;
}
