
#include <cassert>
#include <iostream>
#include <vector>

#ifndef STRONGLY_CONNECTED_COMPONENTS
#define STRONGLY_CONNECTED_COMPONENTS

class StronglyConnectedComponents {
public:
  StronglyConnectedComponents(const std::vector<std::vector<int>> &g) {
    int n = g.size();
    std::vector<std::vector<int>> rg(n);
    for (int i = 0; i < n; i++) {
      for (const auto &v : g[i]) {
        rg[v].push_back(i);
      }
    }
    int now_id = 0;
    std::vector<int> id(n);
    std::vector<bool> visited(n, false);
    for (int i = 0; i < n; i++) {
      now_id = dfs(i, now_id, id, visited, g);
    }

    int comp_id = 0;
    visited.assign(n, false);
    components_id.resize(n);
    for (int i = n - 1; i >= 0; i--) {
      rdfs(id[i], comp_id, visited, rg);
      comp_id++;
    }
  }

  int get(int i) const {
    assert(0 <= i && i < static_cast<int>(components_id.size()));
    return components_id[i];
  }

private:
  int dfs(int cur, int now_id, std::vector<int> &id, std::vector<bool> &visited,
          const std::vector<std::vector<int>> &g) {
    if (visited[cur])
      return now_id;
    visited[cur] = true;
    for (const auto &v : g[cur]) {
      now_id = dfs(v, now_id, id, visited, g);
    }
    id[now_id] = cur;
    now_id++;
    return now_id;
  }

  void rdfs(int cur, int comp_id, std::vector<bool> &visited, const std::vector<std::vector<int>> &g) {
    if (visited[cur])
      return;
    visited[cur] = true;
    components_id[cur] = comp_id;
    for (const auto v : g[cur]) {
      rdfs(v, comp_id, visited, g);
    }
  }

  std::vector<int> components_id;
};

using SCC = StronglyConnectedComponents;

#endif
