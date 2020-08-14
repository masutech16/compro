
#include <functional>
#include <limits>
#include <queue>
#include <vector>

#ifndef DINIC
#define DINIC

template <typename T> struct Edge {
  int to;
  T cap;
  int rev; // 逆向きの辺のidx
};

template <typename T> class Dinic {
private:
  int n;
  std::vector<std::vector<Edge<T>>> g;
  std::vector<int> distance; // 辺の重みを1としたときの距離
  std::vector<int> next_idx; // 各頂点から出る辺についてどこまでチェックしたか

public:
  Dinic(int n) : n(n), g(n), distance(n), next_idx(n) {}

  void add_edge(int from, int to, T cap) {
    g[from].push_back({to, cap, static_cast<int>(g[to].size())});
    g[to].push_back({from, 0, static_cast<int>(g[from].size()) - 1});
  }

  // sからtへの最大流を計算する
  T calc(int s, int t) {
    T ans(0);
    for (int i = 0; i < n; i++) {
      bfs(s);
      if (distance[t] < 0)
        return ans;
      for (auto &el : next_idx) {
        el = 0;
      }
      while (true) {
        T f = dfs(s, t, std::numeric_limits<T>::max());
        if (f <= 0)
          break;
        ans += f;
      }
    }
    return ans;
  }

private:
  void bfs(int s) {
    for (int i = 0; i < n; i++) {
      distance[i] = -1;
    }

    std::queue<int> q;
    distance[s] = 0;
    q.push(s);
    while (!q.empty()) {
      int v = q.front();
      q.pop();
      for (const auto &ne : g[v]) {
        if (ne.cap > 0 && distance[ne.to] < 0) {
          distance[ne.to] = distance[v] + 1;
          q.push(ne.to);
        }
      }
    }
  }

  // vからtに向かう際に流せる量を調べる
  T dfs(int v, int t, T f) {
    if (v == t)
      return f;
    for (int i = next_idx[v]; i < static_cast<int>(g[v].size()); i++) {
      auto &edge = g[v][i];
      if (edge.cap > 0 && distance[v] < distance[edge.to]) {
        T d = dfs(edge.to, t, std::min(f, edge.cap));
        if (d > 0) {
          edge.cap -= d;
          g[edge.to][edge.rev].cap += d;
          return d;
        }
      }
    }
    return 0;
  }
};

#endif
