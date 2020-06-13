#include "../generator/integer.hpp"
#include <cassert>
#include <cstdint>
#include <string>
#include <vector>

#ifndef ROLLING_HASH
#define ROLLING_HASH
class RollingHash {
  using u64 = std::uint_fast64_t;

private:
  constexpr static u64 h = (1uLL << 61) - 1;
  u64 b;
  std::vector<u64> hash, pow;

  u64 mul(u64 a, u64 b) {
    const u64 m30 = (1ull << 30) - 1;
    const u64 m31 = (1ull << 31) - 1;
    u64 au = a >> 31;
    u64 ad = a & m31;
    u64 bu = b >> 31;
    u64 bd = b & m31;
    u64 mid = ad * bu + au * bd;
    u64 mid_u = mid >> 30;
    u64 mid_d = mid & m30;
    u64 res = au * bu * 2 + mid_u + (mid_d << 31) + ad * bd;
    return mod(res);
  }

  u64 mod(u64 x) {
    const u64 xu = x >> 61;
    const u64 xd = x & ((1uLL << 61) - 1);
    ulong res = xu + xd;
    if (res >= h)
      res -= h;
    return res;
  }

public:
  RollingHash(std::string str, u64 base = 0) {
    if (base == 0) {
      IntegerGenerator<u64> ig;
      b = ig.gen(0, h - 1);
    } else {
      b = base;
    }

    int size = str.length();
    hash.assign(size + 1, 0);
    pow.assign(size + 1, 0);

    hash[0] = 0LL;
    pow[0] = 1LL;
    for (int i = 0; i < size; i++) {
      pow[i + 1] = mul(pow[i], b);
      hash[i + 1] = mul(hash[i], b) + str[i];
      if (hash[i + 1] >= h)
        hash[i + 1] -= h;
    }
  }

  // [l,r)に対応するローリングハッシュを取得する
  u64 get(int l, int r) {
    assert(r < (int)hash.size() && l < r);
    u64 ret = hash[r] + h - mul(hash[l], pow[r - l]);
    if (ret >= h)
      ret -= h;
    return ret;
  }

  // bを取得する
  u64 get_base() { return b; }
};
#endif
