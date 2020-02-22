#include <algorithm>
#include <cassert>
#include <vector>

#include <iostream>

template <class T> class Compress {
public:
  explicit Compress(const std::vector<T> &argv) {
    isBuilt = false;
    add(argv);
  }

  Compress() { isBuilt = false; }

  void add(const std::vector<T> &argv) {
    for (const auto &x : argv) {
      add(x);
    }
  }
  void add(const T x) {
    assert(!this->isBuilt);
    v.emplace_back(x);
  }

  void build() {
    isBuilt = true;
    std::sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  }

  int get(const T x) const {
    assert(this->isBuilt);
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }

  const T &operator[](const int k) const { return v[k]; }

private:
  std::vector<T> v;
  bool isBuilt;
};

// verify: https://atcoder.jp/contests/abc036/tasks/abc036_c
int main() {
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  Compress<int> c(a);
  c.build();

  for (int i = 0; i < n; i++) {
    std::cout << c.get(a[i]) << std::endl;
  }
  return 0;
}
