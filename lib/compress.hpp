#include <algorithm>
#include <cassert>
#include <iostream>
#include <vector>
#ifndef COMPRO_COMPRESS
#define COMPRO_COMPRESS

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
    assert(!isBuilt);
    v.emplace_back(x);
  }

  void build() {
    isBuilt = true;
    std::sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
  }

  int get(const T x) const {
    assert(isBuilt);
    return lower_bound(v.begin(), v.end(), x) - v.begin();
  }

  const T &operator[](const int k) const { return v[k]; }

  int size() const { return v.size(); }

private:
  std::vector<T> v;
  bool isBuilt;
};
#endif
