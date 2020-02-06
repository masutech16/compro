#include <cstdint>

#include <iostream>

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
    ModInt el = ModInt(1);
    for (int i = 1; i < n + 1; i++) {
      res *= el;
      el++;
    }

    ModInt inv = ModInt(1);
    el = ModInt(1);
    for (int i = 1; i < r + 1; i++) {
      inv *= el;
      el++;
    }
    el = ModInt(1);
    for (int i = 1; i < n - r + 1; i++) {
      inv *= el;
      el++;
    }
    res *= inv.inv();
    return res;
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

// verify https://atcoder.jp/contests/abc127/tasks/abc127_e
int main() {
  mint n, m, k;
  std::cin >> n >> m >> k;
  mint ans = mint(0);
  mint kumi = mint::comb(n * m - mint(2), k - mint(2));
  for (int d = 1; d < n.getValue(); d++) {
    ans += (mint(d) * (n - mint(d)) * m * m * kumi);
  }
  for (int d = 1; d < m.getValue(); d++) {
    ans += (mint(d) * (m - mint(d)) * n * n * kumi);
  }
  std::cout << ans << std::endl;
}
