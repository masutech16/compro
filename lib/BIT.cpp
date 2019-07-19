#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;

using namespace std;

struct BIT
{
  vector<int> bit;
  int size;

  BIT(int n)
  {
    bit = vector<int>(n + 1);
    size = n;
  }

  int sum(int i)
  {
    if (i == 0)
    {
      return 0;
    }
    return bit[i] + sum(i - (i & -i))
  }

  void add(int i, int x)
  {
    if (i > size)
    {
      return;
    }
    bit[i] += x;
    add(i - (i & -i));
  }
};
