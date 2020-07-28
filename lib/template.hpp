#ifndef TEMPLATE
#define TEMPLATE
#include "io/vector.hpp"
#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ALL(v) (v).begin(), (v).end()
#define coutd(n) cout << fixed << setprecision(n)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
#define MM << " " <<

using namespace std;

template <class T> void say(bool val, T yes, T no) { cout << (val ? yes : no) << "\n"; }

void say(bool val, string yes = "Yes", string no = "No") { say<string>(val, yes, no); }

template <class T> void chmin(T &a, T b) {
  if (a > b)
    a = b;
}

template <class T> void chmax(T &a, T b) {
  if (a < b)
    a = b;
}

// C++ 17に完全移行したら消す
// 最大公約数を求める
template <class T> T gcd(T n, T m) { return n ? gcd(m % n, n) : m; }

// 最小公倍数を求める
template <class T> T lcm(T n, T m) {
  int g = gcd(n, m);
  return n * m / g;
}

// 重複を消す。計算量はO(NlogN)
template <class T> void unique(std::vector<T> &v) {
  std::sort(v.begin(), v.end());
  v.erase(std::unique(v.begin(), v.end()), v.end());
}

#endif
