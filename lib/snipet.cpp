#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int

using namespace std;
// stringをintに変換する
int to_int(string s)
{
  return atoi(s.c_str());
}

// 自作した二分探索
int my_binary_search(int *data, int size, int key, int ok, int ng)
{
  while (abs(ok - ng) > 1)
  {
    int mid = (ok + ng) / 2;

    if (data[mid] >= key)
    {
      ok = mid;
    }
    else
    {
      ng = mid;
    }
  }
  return ok;
}

// 最大公約数を求める関数
int gcd(int n, int m)
{
  if (n < m)
  {
    int tmp = m;
    m = n;
    n = tmp;
  }
  if (m == 0)
  {
    return n;
  }
  return gcd(m, n % m);
}

// 最小公倍数を求める関数
int lcm(int n, int m)
{
  int g = gcd(n, m);
  return n * m / g;
}

// 素因数分解
// 特に返り値とかは返しません
// vector<int> pがグローバル変数にあることを期待しています
int factor(int n)
{
  while (n != 1)
  {
    vector<int> p;
    bool flg = true;
    FOR(i, 2, (int)sqrt(n) + 1)
    {
      if (n % i == 0)
      {
        p.push_back(i);
        n = n / i;
        flg = false;
        break;
      }
    }
    if (flg)
    {
      p.push_back(n);
      break;
    }
  }
}

// 小数を表示する
void printDouble(double n, int digits)
{
  cout << fixed << setprecision(digits) << n << endl;
}

// 重複を消す
void unique(vector<T> v)
{
  sort(v.begin(), v.end());
  v.erase(unique(v.begin(), v.end()), v.end());
  return v;
}
