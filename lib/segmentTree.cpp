#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, m, n) for (int i = m; i < n; i++)
#define ll long long int
const int INF = 2147483647;
const ll MOD = 1000000007;

using namespace std;

class SegmentTree {
public:
  SegmentTree(const int n, const int identity);
  void update(const int index, const int value);
  int find(const int l, const int r);

private:
  int leftChildIndex(const int parent);
  int rightChildIndex(const int parent);
  int parent(const int child);
  int leaf(const int index);
  int query(const int l, const int r, const int node, const int al,
            const int ar);

private:
  vector<int> array;
  int size;
  int id;
};

SegmentTree::SegmentTree(const int n, const int identity) {
  id = identity;
  size = 1;
  while (size < n)
    size *= 2;
  array = vector<int>(2 * size - 1, id);
}

int SegmentTree::leftChildIndex(const int parent) { return parent * 2 + 1; }
int SegmentTree::rightChildIndex(const int parent) { return parent * 2 + 2; }
int SegmentTree::parent(const int child) { return (child - 1) / 2; }
int SegmentTree::leaf(const int index) { return index + size - 1; }
int SegmentTree::find(const int l, const int r) {
  return query(l, r, 0, 0, size);
}

int SegmentTree::query(const int l, const int r, const int node, const int al,
                       const int ar) {
  if (r <= al || ar <= l)
    return id;
  if (l <= al && ar <= r)
    return array[node];
  int mid = (al + ar) / 2;
  int leftValue = query(l, r, leftChildIndex(node), al, mid);
  int rightValue = query(l, r, rightChildIndex(node), mid, ar);
  return min(leftValue, rightValue);
}

void SegmentTree::update(const int index, const int value) {
  int i = leaf(index);
  array[i] = value;
  while (i > 0) {
    i = parent(i);
    array[i] = min(array[rightChildIndex(i)], array[leftChildIndex(i)]);
  }
}

int main() {
  int n, q;
  cin >> n >> q;
  SegmentTree seg = SegmentTree(n, 2147483647);
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
