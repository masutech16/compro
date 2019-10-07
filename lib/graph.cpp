#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;
typedef std::vector<std::vector<int>> graph;

// 二部グラフ判定
// 0: 調べてない, 1,-1: 塗り分け後
int checked[max_v] = {};
bool isBipartite(const graph &g, int parent, int i, int c) {
  if (checked[i] != 0) {
    return checked[i] == c;
  }
  checked[i] = c;
  for (auto v : g[i]) {
    if (v == parent)
      continue;
    if (!isBipartite(g, i, v, -c)) {
      return false;
    }
  }
  return true;
}
