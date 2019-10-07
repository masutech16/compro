#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

struct UnionFind {
  vector<int> par; // par[i]が親を表す

  // コンストラクタ
  UnionFind(int n) {
    par = vector<int>(n);
    for (int i = 0; i < n; i++) {
      par[i] = i;
    }
  }

  // データxの根を求める
  int root(int x) {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]); // 木構造の縮約を行っている
  }

  // xとyの親が違うとき、マージする。そのときyの根がxの根の子になる
  void merge(int x, int y) {
    int rootx = root(x);
    int rooty = root(y);
    if (rootx == rooty)
      return;
    par[rooty] = rootx;
  }

  // 同じグループに属しているか
  bool isSame(int x, int y) { return root(x) == root(y); }
};

struct edge {
  int u, v, cost
};

bool comp(const edge &e1, const edge &e2) { return e1.cost < e2.cost; }

// 最小全域木のコストを求める
int kruskal(vector<edge> &edges, const int size) {
  sort(edges.begin(), edges.end(), comp);
  UnionFind uf(size);
  int res = 0;
  for (auto e : edges) {
    if (!uf.isSame(e.u, e.v)) {
      uf.merge(e.u, e.v);
      res += e.cost;
    }
  }
  return res;
}

int main() {}
