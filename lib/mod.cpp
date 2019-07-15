#include <bits/stdc++.h>

#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, n, m) for (int i = n; i < m; i++)
#define ll long long int

using namespace std;

// 剰余体における逆元の算出用メソッド
ll modpow(ll a, ll n, ll mod)
{
  ll res = 1;
  while (n > 0)
  {
    if (n & 1)
      res = res * a % mod;
    a = a * a % mod;
    n >>= 1;
  }
  return res;
}

ll modinv(ll a, ll mod)
{
  return modpow(a, mod - 2, mod);
}

ll modnCr(ll n, ll r, ll mod)
{
  ll ans = 1;
  FOR(i, 1, n + 1)
  {
    ans = (ans * i) % mod;
  }
  ll inv = 1;
  FOR(i, 1, r + 1)
  {
    inv = (inv * i) % mod;
  }
  FOR(i, 1, n - r + 1)
  {
    inv = (inv * i) % mod;
  }

  ans = (ans * modinv(inv, mod)) % mod;
  return ans;
}
