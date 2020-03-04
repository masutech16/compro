#include <cstdint>
#include <iostream>
#ifndef MOD_INT
#define MOD_INT

template <std::uint_fast64_t MOD> class ModInt {
  using u64 = std::uint_fast64_t;

public:
  ModInt(const u64 val = 0) { value = val % MOD; }

  bool operator==(const ModInt &rhs) const { return value == rhs.value; }
  bool operator!=(const ModInt &rhs) const { return !(*this == rhs); }
  bool operator<(const ModInt &rhs) const { return value < rhs.value; }
  bool operator>(const ModInt &rhs) const { return value > rhs.value; }
  bool operator<=(const ModInt &rhs) const { return !(*this > rhs); }
  bool operator>=(const ModInt &rhs) const { return !(*this < rhs); }

  ModInt operator+(const ModInt rhs) const { return ModInt(*this) += rhs; }
  ModInt operator-(const ModInt rhs) const { return ModInt(*this) -= rhs; }
  ModInt operator*(const ModInt rhs) const { return ModInt(*this) *= rhs; }
  ModInt operator/(const ModInt rhs) const { return ModInt(*this) /= rhs; }

  ModInt &operator+=(const ModInt rhs) {
    value += rhs.value;
    if (value >= MOD) {
      value -= MOD;
    }
    return *this;
  }

  ModInt &operator-=(const ModInt rhs) {
    if (value < rhs.value) {
      value += MOD;
    }
    value -= rhs.value;
    return *this;
  }

  ModInt &operator*=(const ModInt rhs) {
    value = value * rhs.value % MOD;
    return *this;
  }

  ModInt &operator/=(ModInt rhs) {
    *this *= rhs.inv();
    return *this;
  }

  ModInt &operator++(int n) {
    value++;
    if (value >= MOD) {
      value -= MOD;
    }
    return *this;
  }

  ModInt &operator--(int n) {
    if (value == 0) {
      value += MOD;
    }
    value--;
    return *this;
  }

  ModInt inv() { return ModInt::pow(*this, MOD - 2); }

  static ModInt pow(ModInt base, long long int n) {
    ModInt res = ModInt(1);
    while (n) {
      if (n & 1) {
        res *= base;
      }
      base *= base;
      n /= 2;
    }
    return res;
  }

  static ModInt comb(ModInt n, ModInt r) { return comb(n.value, r.value); }

  static ModInt comb(int n, int r) {
    if (n < r)
      return ModInt(0);
    ModInt res = ModInt(1);
    for (int i = 0; i < r; i++) {
      res *= ModInt(n - i);
    }

    ModInt inv = ModInt(1);
    for (int i = 0; i < r; i++) {
      inv *= ModInt(r - i);
    }
    return res / inv;
  }

  u64 getValue() const { return value; }

private:
  u64 value;
};

// ここを問題ごとのMODに書き換える
using mint = ModInt<1000000007>;

std::ostream &operator<<(std::ostream &out, const mint &m) {
  out << m.getValue();
  return out;
};

std::istream &operator>>(std::istream &in, mint &m) {
  uint_fast64_t i;
  in >> i;
  m = mint(i);
  return in;
}
#endif
