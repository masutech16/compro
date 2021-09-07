#ifndef TEMPLATE
#define TEMPLATE
#include "Assert/Assert.hpp"
#include "io/vector.hpp"
#include <bits/stdc++.h>
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

struct P {
  ll x;
  ll y;
};

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}

// 重複を消す。計算量はO(NlogN)
template <class T> void unique(std::vector<T> &v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
}

#endif
