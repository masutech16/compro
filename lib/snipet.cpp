#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int

using namespace std;
// stringをintに変換する
int to_int(string s) { return atoi(s.c_str()); }

// 自作した二分探索
int my_binary_search(int *data, int size, int key, int ok, int ng) {
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (data[mid] >= key) {
      ok = mid;
    } else {
      ng = mid;
    }
  }
  return ok;
}

// 最大公約数を求める関数
int gcd(int n, int m) { return n ? gcd(m % n, n) : m; }

// 最小公倍数を求める関数
int lcm(int n, int m) {
  int g = gcd(n, m);
  return n * m / g;
}

// 重複を消す
void unique(vector<T> v) {
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
