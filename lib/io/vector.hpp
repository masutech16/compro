#include <iostream>
#include <vector>

#ifndef IO_VECTOR
#define IO_VECTOR

template <class T> std::ostream &operator<<(std::ostream &out, const std::vector<T> &v) {
  int size = v.size();
  for (int i = 0; i < size; i++) {
    std::cout << v[i];
    if (i != size - 1)
      std::cout << " ";
  }
  return out;
}

template <class T> std::istream &operator>>(std::istream &in, std::vector<T> &v) {
  for (auto &el : v) {
    std::cin >> el;
  }
  return in;
}

#endif
