#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int

struct edge {
  int to, cost;
};
typedef std::vector<std::vector<edge>> graph;
const ll MOD = 1000000007;
using namespace std;

int v; // 頂点数
// d[u][v]はu=vならば0、辺(u,v)があればそのコスト、なければINFで初期化
int d[v][v] = {};
void warshallFloyd() {

  REP(k, v) {
    REP(i, v) {
      REP(j, v) { d[i][j] = min(d[i][j], d[i][k] + d[k][j]); }
    }
  }
}
