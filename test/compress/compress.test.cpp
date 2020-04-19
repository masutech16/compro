#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_4_A"
#include "../../lib/compress.hpp"
#include <iostream>
#include <vector>

int main() {
  int n;
  std::cin >> n;
  std::vector<long long int> vx1, vx2, vy1, vy2;
  Compress<long long int> vx, vy;
  for (int i = 0; i < n; i++) {
    int x1, x2, y1, y2;
    std::cin >> x1 >> y1 >> x2 >> y2;
    vx1.emplace_back(x1);
    vx2.emplace_back(x2);
    vy1.emplace_back(y1);
    vy2.emplace_back(y2);
  }

  vx.add(vx1);
  vx.add(vx2);
  vy.add(vy1);
  vy.add(vy2);
  vx.build();
  vy.build();

  for (int i = 0; i < n; i++) {
    vx1[i] = vx.get(vx1[i]);
    vx2[i] = vx.get(vx2[i]);
    vy1[i] = vy.get(vy1[i]);
    vy2[i] = vy.get(vy2[i]);
  }

  std::vector<std::vector<int>> imos(2 * n, std::vector<int>(2 * n, 0));
  for (int i = 0; i < n; i++) {
    imos[vx1[i]][vy1[i]]++;
    imos[vx2[i]][vy1[i]]--;
    imos[vx1[i]][vy2[i]]--;
    imos[vx2[i]][vy2[i]]++;
  }

  for (int i = 0; i < 2 * n; i++) {
    for (int j = 1; j < 2 * n; j++) {
      imos[i][j] += imos[i][j - 1];
    }
  }
  for (int j = 0; j < 2 * n; j++) {
    for (int i = 1; i < 2 * n; i++) {
      imos[i][j] += imos[i - 1][j];
    }
  }

  long long int ans = 0;
  for (int i = 0, xSize = vx.size(); i < xSize - 1; i++) {
    for (int j = 0, ySize = vy.size(); j < ySize - 1; j++) {
      if (imos[i][j] > 0)
        ans += (vx[i + 1] - vx[i]) * (vy[j + 1] - vy[j]);
    }
  }

  std::cout << ans << std::endl;
  return 0;
}
