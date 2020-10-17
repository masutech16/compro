#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_5_A"
#include "../../lib/geometry/closest_pair.hpp"
#include <iomanip>
#include <iostream>

int main() {
  int n;
  std::cin >> n;
  std::vector<P<double>> xy(n);
  for (int i = 0; i < n; i++) {
    double x, y;
    std::cin >> x >> y;
    xy[i] = {x, y};
  }

  std::cout << std::fixed << std::setprecision(10) << closest_pair<double>(xy) << std::endl;
}
