#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

template <class T> class SegmentTree {
public:
  SegmentTree(const int n, const T id, function<T(T, T)> op,
              function<T(T, T)> updateOp);
  void update(const int index, const T value);
  T find(const int l, const int r);

private:
  int leftChildIndex(const int parent);
  int rightChildIndex(const int parent);
  int parent(const int child);
  int leaf(const int index);
  T query(const int l, const int r, const int node, const int al, const int ar);

private:
  vector<T> data;
  int leafNum;
  T id;
  function<T(T, T)> op;
  function<T(T, T)> updateOp;
};

template <class T>
SegmentTree<T>::SegmentTree(const int n, const T id, function<T(T, T)> op,
                            function<T(T, T)> updateOp)
    : id(id), op(op), updateOp(updateOp) {
  leafNum = 1;
  while (leafNum < n)
    leafNum *= 2;
  data = vector<T>(2 * leafNum - 1, id);
}

template <class T> int SegmentTree<T>::leftChildIndex(const int parent) {
  return parent * 2 + 1;
}

template <class T> int SegmentTree<T>::rightChildIndex(const int parent) {
  return parent * 2 + 2;
}

template <class T> int SegmentTree<T>::parent(const int child) {
  return (child - 1) / 2;
}

template <class T> int SegmentTree<T>::leaf(const int index) {
  return index + leafNum - 1;
}

template <class T> T SegmentTree<T>::find(const int l, const int r) {
  return query(l, r, 0, 0, leafNum);
}

template <class T>
T SegmentTree<T>::query(const int l, const int r, const int node, const int al,
                        const int ar) {
  if (r <= al || ar <= l)
    return id;
  if (l <= al && ar <= r)
    return data[node];
  int mid = (al + ar) / 2;
  T leftValue = query(l, r, leftChildIndex(node), al, mid);
  T rightValue = query(l, r, rightChildIndex(node), mid, ar);
  return op(leftValue, rightValue);
}

template <class T> void SegmentTree<T>::update(const int index, const T value) {
  int i = leaf(index);
  data[i] = updateOp(data[i], value);
  while (i > 0) {
    i = parent(i);
    data[i] = op(data[rightChildIndex(i)], data[leftChildIndex(i)]);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  SegmentTree<ll> seg(n, (1LL << 31) - 1,
                      [](ll a, ll b) -> ll { return min(a, b); },
                      [](ll a, ll b) -> ll { return b; });
  REP(i, q) {
    int com, x, y;
    cin >> com >> x >> y;
    if (com == 0) {
      seg.update(x, y);
    } else {
      cout << seg.find(min(x, y), max(x, y) + 1) << endl;
    }
  }
}
