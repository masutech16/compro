#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

typedef Type int;
typedef vector<vector<Type>> Matrix;

Matrix mul(const Matrix &a, const Matrix &b)
{
  Matrix c(a.size(), vector<Type>(b[0].size()));
  for (int i = 0; i < a.size(); i++)
  {
    for (int k = 0; k < b.size(); k++)
    {
      for (int j = 0; j < b[0].size(); j++)
      {
        c[i][j] = (c[i][j] + a[i][k] * b[k][j]);
      }
    }
  }
  return c;
}

Matrix pow(Matrix &a, int n)
{
  Matrix res(a.size(), vector<Type>(a[0].size()));
  while (n > 0)
  {
    if (n & 1)
      res = mul(res, a);
    a = mul(a, a);
    n >>= 1;
  }
  return res;
}

void PrintMatrix(const Matrix &a)
{
  int h = a.size(), w = a[0].size();
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      cout << a[i][j] << ' ';
    }
    cout << endl;
  }
}
