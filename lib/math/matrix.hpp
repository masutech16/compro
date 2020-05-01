
#include <cassert>
#include <iostream>
#include <vector>
#ifndef COMPRO_MATRIX
#define COMPRO_MATRIX

// TODO: もう少し良い定義の仕方があると思うけどとりあえずはこれで
template <class T> class Matrix {
private:
  const int row;
  const int column;

public:
  std::vector<std::vector<T>> val;

  Matrix(int row, int column) {
    val = std::vector<std::vector<T>>(row, std::vector<T>(column, 0));
    row = row;
    column = column;
  }

  Matrix operator+(const Matrix rhs) const { return Matrix(*this) += rhs; }
  Matrix operator-(const Matrix rhs) const { return Matrix(*this) -= rhs; }
  Matrix operator*(const Matrix rhs) const { return Matrix(*this) *= rhs; }

  Matrix operator+=(const Matrix rhs) {
    assert(rhs.row == row && rhs.column == column);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        val[i][j] += rhs.val[i][j];
      }
    }
    return *this;
  }

  Matrix operator-=(const Matrix rhs) {
    assert(rhs.row == row && rhs.column == column);
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        val[i][j] -= rhs.val[i][j];
      }
    }
    return *this;
  }

  Matrix operator*=(const Matrix rhs) {
    assert(column == rhs.row);
    Matrix ret(row, rhs.column);
    for (int i = 0; i < row; i++) {
      for (int k = 0; k < column; k++) {
        for (int j = 0; j < rhs.column; j++) {
          ret[i][j] += val[i][k] * rhs.val[k][j];
        }
      }
    }
    return ret;
  }

  // T(1)が単位元であることを仮定している。
  Matrix pow(int n) {
    assert(row == column);
    Matrix ret(row, column), a = Matrix(*this);
    for (int i = 0; i < row; i++) {
      ret[i][i] = T(1);
    }
    while (n > 0) {
      if (n & 1)
        ret *= a;
      a *= a;
      n >>= 1;
    }
    return ret;
  }

  void print() {
    for (int i = 0; i < row; i++) {
      for (int j = 0; j < column; j++) {
        std::cout << val[i][j] << (j == column - 1 ? "\n" : " ");
      }
    }
  }
};
#endif
