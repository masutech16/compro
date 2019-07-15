#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ll long long int

struct edge
{
  int to, cost;
};
typedef vector<vector<edge>> graph;
const ll MOD = 1000000007;
using namespace std;

int d[100000] = {};

void dijkstra(int s, int n, graph g)
{
  // (最短距離, 頂点)
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

  fill(d, d + n, INT_MAX);
  d[s] = 0;
  q.push(make_pair(0, s));

  while (!q.empty())
  {
    auto p = q.top();
    q.pop();

    int v = p.second;
    if (d[v] < p.first)
      continue;
    REP(i, g[v].size())
    {
      auto e = g[v][i];
      if (d[e.to] > d[v] + e.cost)
      {
        d[e.to] = d[v] + e.cost;
        q.push(make_pair(d[e.to], e.to));
      }
    }
  }
}
