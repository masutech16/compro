#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
#define vl vector<ll>
#define vi vector<int>
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

// 二部グラフ判定を行なう
typedef std::vector<std::vector<int>> graph;

// -1,0,1のいずれか. 0は未着色
bool isbipartite(int v, int par, int color, vector<int> &data, const graph &g) {
  if (data[v] != 0)
    if (data[v] != color) {
      return false;
    } else {
      return true;
    }
  data[v] = color;
  for (auto u : g[v]) {
    if (u == par)
      continue;
    if (!isbipartite(u, v, -color, data, g))
      return false;
  }
  return true;
}
