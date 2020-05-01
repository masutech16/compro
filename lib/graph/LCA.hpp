#include "../doubling.hpp"
#include <cmath>
#include <vector>
#ifndef COMPRO_LCA
#define COMPRO_LCA

class LCA {
private:
  std::vector<std::vector<int>> next;
  int size;

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

public:
  LCA(std::vector<std::vector<int>> next) {
    next = next;
    size = next[0].size();
  }

  LCA(std::vector<int> seed) {
    this->next = doubling(seed, -1);
    size = next[0].size();
  }

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
};
#endif
