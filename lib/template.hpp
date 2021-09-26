#ifndef TEMPLATE
#define TEMPLATE
#include "Assert/Assert.hpp"
#include "IO/Pair.hpp"
#include "IO/Vector.hpp"
#include <algorithm>
#define REP(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, m, n) for (int i = (m); i < (n); i++)
#define RREP(i, n) for (int i = (n - 1); i >= 0; i--)
#define RFOR(i, m, n) for (int i = (n - 1); i >= (m); i--)
#define ALL(v) std::begin(v), std::end(v)
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}

template <class T> void unique(std::vector<T> &v) {
  std::sort(std::begin(v), std::begin(v));
  v.erase(std::unique(std::begin(v), std::end(v)), std::end(v));
}

template <class F, class T> bool if_all(std::vector<T> &v, F &&func) {
  return std::all_of(std::begin(v), std::end(v), func);
}

template <class F, class T> bool if_any(std::vector<T> &v, F &&func) {
  return std::any_of(std::begin(v), std::end(v), func);
}

#endif
