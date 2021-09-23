#include "../utils/doubling.hpp"
#include <cmath>
#include <vector>
#ifndef COMPRO_LCA
#define COMPRO_LCA

// LCAを計算するクラス
class LCA {
private:
  std::vector<std::vector<int>> next;
  int size;

public:
  // コンストラクタ
  // next: ダブリング済みの配列
  LCA(std::vector<std::vector<int>> next) {
    next = next;
    size = next[0].size();
  }

  // コンストラクタ
  // seed: i番目には頂点iの親の頂点番号を入れる。
  LCA(std::vector<int> seed) {
    this->next = doubling(seed, -1);
    size = next[0].size();
  }

  // 頂点uのdeg個上の頂点を返す
  int anc(int u, int deg) {
    int cur = u;
    int cnt = 0;
    while (deg > 0) {
      if (cur == -1)
        break;
      if (deg % 2 == 1) {
        cur = next[cnt][cur];
      }
      cnt++;
      deg /= 2;
    }
    return cur;
  }

  // 頂点uの根からの距離を返す
  int length(int u) {
    int ok = 0;
    int ng = size;
    while (std::abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (anc(u, mid) != -1) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    return ok;
  }

  // 頂点uとvのLCAを返す。
  int get(int u, int v) {
    int lu = length(u), lv = length(v);
    if (lu > lv) {
      u = anc(u, lu - lv);
    } else {
      v = anc(v, lv - lu);
    }

    int ok = size;
    int ng = -1;
    while (std::abs(ok - ng) > 1) {
      int mid = (ok + ng) / 2;
      if (anc(u, mid) == anc(v, mid)) {
        ok = mid;
      } else {
        ng = mid;
      }
    }
    return anc(u, ok);
  }

  int dist(int u, int v) {
    int lca = get(u, v);
    return length(u) + length(v) - 2 * length(lca);
  }
};
#endif
