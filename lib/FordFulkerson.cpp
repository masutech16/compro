#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

struct edge
{
  int to, cap, rev;
};
typedef std::vector<std::vector<edge>> graph;

bool used[103] = {};

void addEdge(int from, int to, int cap, graph &g)
{
  g[from].push_back({to, cap, (int)g[to].size()});
  g[to].push_back({from, 0, (int)g[from].size() - 1});
}

// t:sink
int dfs(int v, int t, int f, graph &g)
{
  if (v == t)
    return f;
  used[v] = true;
  for (auto &e : g[v])
  {
    if (!used[e.to] && e.cap > 0)
    {
      int d = dfs(e.to, t, min(f, e.cap), g);
      if (d > 0)
      {
        e.cap -= d;
        g[e.to][e.rev].cap += d;
        return d;
      }
    }
  }
  return 0;
}

int fordFulkerson(int s, int t, graph &g)
{
  int flow = 0;
  while (true)
  {
    REP(i, g.size())
    {
      used[i] = false;
    }
    int f = dfs(s, t, INF, g);
    if (f == 0)
      return flow;
    flow += f;
  }
}

int main()
{
  int v, e;
  cin >> v >> e;
  graph g(v);
  REP(i, e)
  {
    int u, v, c;
    cin >> u >> v >> c;
    addEdge(u, v, c, g);
  }

  cout << fordFulkerson(0, v - 1, g) << endl;
}
