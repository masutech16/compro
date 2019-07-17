#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;
struct edge
{
  int to, cost;
};
typedef std::vector<std::vector<edge>> graph;

graph prim(const graph &g, const int size, const int init)
{
  int mincost[size] = {};
  bool used[size] = {};

  REP(i, size)
  {
    mincost[i] = INF;
  }

  mincost[init] = 0;
  graph res(size);
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
  for (auto v : g[init])
  {
    q.push(make_pair(v.cost, make_pair(init, v.to)));
  }
  used[init] = true;

  while (!q.empty())
  {
    auto p = q.top();
    q.pop();
    auto e = p.second;

    if (used[e.second])
      continue;

    res[e.first].push_back({e.second, p.first});
    res[e.second].push_back({e.first, p.first});

    for (auto v : g[e.second])
    {
      q.push(make_pair(v.cost, make_pair(e.second, v.to)));
    }
    used[e.second] = true;
  }
  return res;
}

int main()
{
  int v, e;
  cin >> v >> e;
  graph g(v);
  REP(i, e)
  {
    int s, t, w;
    cin >> s >> t >> w;
    g[s].push_back({t, w});
    g[t].push_back({s, w});
  }

  graph res = prim(g, v, 0);

  int ans = 0;
  REP(i, v)
  {
    for (auto vi : res[i])
    {
      ans += vi.cost;
    }
  }
  cout << ans / 2 << endl;
}
