#include <iostream>

#ifndef IO_PAIR
#define IO_PAIR

template <class T1, class T2> std::ostream &operator<<(std::ostream &out, const std::pair<T1, T2> &p) {
  std::cout << p.first << ' ' << p.second;
  return out;
}

template <class T1, class T2> std::istream &operator>>(std::istream &in, std::pair<T1, T2> &p) {
  std::cin >> p.first >> p.second;
  return in;
}

#endif
