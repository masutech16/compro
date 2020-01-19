#include <vector>

#include <iostream>

// nまでの数が素数かどうかを判定できるvectorを返す
std::vector<bool> factor(const int n) {
  int size = n + 1;
  std::vector<bool> isPrime(size, true);
  isPrime[0] = false;
  isPrime[1] = false;
  for (int i = 2; i < size; i++) {
    if (!isPrime[i])
      continue;
    for (int k = 2; i * k < size; k++) {
      isPrime[i * k] = false;
    }
  }
  return isPrime;
}

// minFactor[i]: iを割り切る最小の素数。存在しない場合は-1。
std::vector<int> fastFactor(const int n) {
  int size = n + 1;
  std::vector<int> minFactor(size, -1);
  for (int i = 2; i < size; i++) {
    if (minFactor[i] != -1)
      continue;
    minFactor[i] = i;
    for (int k = 2; i * k < size; k++) {
      if (minFactor[i * k] == -1) {
        minFactor[i * k] = i;
      }
    }
  }
  return minFactor;
}

// factor
// verify https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/1/ALDS1_1_C
void verify_factor() {
  std::vector<bool> isPrime = factor(10000);
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
}

// fastFactor
// verify https://atcoder.jp/contests/abc052/tasks/arc067_a
void verify_fastFactor() {
  int n;
  std::cin >> n;
  auto minFactor = fastFactor(1000);
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

int main() {
  // verify_factor();
  verify_fastFactor();
  return 0;
}
