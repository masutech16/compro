#ifndef Rational_NUMBER
#define Rational_NUMBER

#include "Assert/Assert.hpp"

template <class T> class Rational {
public:
  Rational(T numerator, T denominator) : numerator(numerator), denominator(denominator) {}

  explicit Rational(T numerator) : numerator(numerator), denominator(1) {}

  T getNumerator() const { return numerator; }

  T getDenominator() const { return denominator; }

private:
  T numerator;
  T denominator;
};

// 比較演算子
template <class T> bool operator<(const Rational<T> &lhs, const Rational<T> &rhs) {
  return lhs.getNumerator() * rhs.getDenominator() < rhs.getNumerator() * lhs.getDenominator();
}
template <class T> bool operator>(const Rational<T> &lhs, const Rational<T> &rhs) { return rhs < lhs; }
template <class T> bool operator<=(const Rational<T> &lhs, const Rational<T> &rhs) { return !(lhs > rhs); }
template <class T> bool operator>=(const Rational<T> &lhs, const Rational<T> &rhs) { return !(lhs < rhs); }
template <class T> bool operator==(const Rational<T> &lhs, const Rational<T> &rhs) {
  return !(lhs < rhs) && !(lhs > rhs);
}
template <class T> bool operator!=(const Rational<T> &lhs, const Rational<T> &rhs) { return !(lhs == rhs); }

#endif
