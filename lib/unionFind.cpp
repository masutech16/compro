// union-find木の実装
#include <vector>
#include <iostream>

using namespace std;

struct UnionFind
{
  vector<int> par;   // par[i]が親を表す
  vector<int> _size; // _size[i]でそのノードの属しているサイズを返す

  // コンストラクタ
  UnionFind(int n)
  {
    _size = vector<int>(n);
    par = vector<int>(n);
    for (int i = 0; i < n; i++)
    {
      par[i] = i;
      _size[i] = 1;
    }
  }

  // データxの根を求める
  int root(int x)
  {
    if (par[x] == x)
      return x;
    return par[x] = root(par[x]); // 木構造の縮約を行っている
  }

  // xとyの親が違うとき、マージする。そのときyの根がxの根の子になる
  void merge(int x, int y)
  {
    int rootx = root(x);
    int rooty = root(y);
    if (rootx == rooty)
      return;
    par[rooty] = rootx;
    int s = _size[rooty] + _size[rootx];
    _size[rooty] = s;
    _size[rootx] = s;
  }

  // xの属している集団のサイズ
  int size(int x)
  {
    return _size[x];
  }

  // 同じグループに属しているか
  bool isSame(int x, int y)
  {
    return root(x) == root(y);
  }
};

// 以下、テストコード
int main()
{
  UnionFind tree(10);

  // 0-1-2-3, 4-7, 5-9という構造にする
  tree.merge(0, 1);
  tree.merge(1, 2);
  tree.merge(2, 3);
  tree.merge(4, 7);
  tree.merge(5, 9);

  cout << "0 and 2 are in the same group (should be true)" << endl;
  cout << tree.isSame(0, 2) << endl;

  cout << "0 and 6 are not in the same group (should be false)" << endl;
  cout << tree.isSame(0, 6) << endl;

  cout << tree.size(0) << endl;
  cout << tree.size(5) << endl;
}