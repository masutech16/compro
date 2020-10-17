#include <algorithm>
#include <cassert>
#include <cmath>
#include <vector>

#ifndef CLOSEST_PAIR
#define CLOSEST_PAIR

template <class T> using P = std::pair<T, T>;

template <class T>
double closest_pair(typename std::vector<P<T>>::iterator begin, typename std::vector<P<T>>::iterator end) {
  int n = end - begin;
  if (n <= 1)
    return std::numeric_limits<double>::max();
  auto mid = begin + (n / 2);
  double x = mid->first;
  double d = std::min(closest_pair<T>(begin, mid), closest_pair<T>(mid, end));

  inplace_merge(begin, mid, end, [](const P<T> &lhs, const P<T> &rhs) { return lhs.second < rhs.second; });

  std::vector<P<T>> b;
  for (auto itr = begin; itr != end; itr++) {
    if (std::abs(itr->first - x) >= d)
      continue;
    int s = b.size();
    for (int i = s - 1; i >= 0; i--) {
      auto dx = itr->first - b[i].first;
      auto dy = itr->second - b[i].second;
      if (dy >= d)
        break;
      d = std::min(d, sqrt(dx * dx + dy * dy));
    }
    b.push_back(*itr);
  }
  return d;
}

template <class T> double closest_pair(std::vector<P<T>> v) {
  std::sort(v.begin(), v.end());
  return closest_pair<T>(v.begin(), v.end());
}

#endif
