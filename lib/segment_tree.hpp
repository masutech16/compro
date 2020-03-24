#include <functional>
#include <vector>
#ifndef SEGMENT_TREE
#define SEGMENT_TREE

template <class T> class SegmentTree {
public:
  SegmentTree(const int n, const T id, std::function<T(T, T)> op, std::function<T(T, T)> updateOp)
      : id(id), op(op), updateOp(updateOp) {
    leafNum = 1;
    while (leafNum < n)
      leafNum *= 2;
    data = std::vector<T>(2 * leafNum - 1, id);
  }

  void update(const int index, const T value) {
    int i = leaf(index);
    data[i] = updateOp(data[i], value);
    while (i > 0) {
      i = parent(i);
      data[i] = op(data[rightChildIndex(i)], data[leftChildIndex(i)]);
    }
  }

  T find(const int l, const int r) { return query(l, r, 0, 0, leafNum); }

private:
  int leftChildIndex(const int parent) { return parent * 2 + 1; }

  int rightChildIndex(const int parent) { return parent * 2 + 2; }

  int parent(const int child) { return (child - 1) / 2; }

  int leaf(const int index) { return index + leafNum - 1; }

  T query(const int l, const int r, const int node, const int al, const int ar) {
    if (r <= al || ar <= l)
      return id;
    if (l <= al && ar <= r)
      return data[node];
    int mid = (al + ar) / 2;
    T leftValue = query(l, r, leftChildIndex(node), al, mid);
    T rightValue = query(l, r, rightChildIndex(node), mid, ar);
    return op(leftValue, rightValue);
  }

private:
  std::vector<T> data;
  int leafNum;
  T id;
  std::function<T(T, T)> op;
  std::function<T(T, T)> updateOp;
};
#endif
