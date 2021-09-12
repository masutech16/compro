#ifndef GRID
#define GRID

#include <iostream>
#include <string>
#include <vector>

#include "Assert/Assert.hpp"

class Grid {
public:
  Grid(int height, int width, const std::vector<std::string> s) : height(height), width(width), board(s) {
    ASSERT_MSG((int)board.size() == height, "盤面の高さが合いません");
    ASSERT_MSG((int)board[0].size() == width, "盤面の横幅が合いません");
  }

  // (i,j)が範囲内にあるかを確認します
  bool in(int i, int j) const { return 0 <= i && i < height && 0 <= j && j < width; }

  // (i,j)成分を取得します。範囲外の場合はエラーになります
  char at(int i, int j) const {
    // TODO: 本当はi,jを出力に埋め込みたい
    ASSERT_MSG(in(i, j), "範囲外アクセスをしようとしています");
    return board[i][j];
  }

  // 高さを取得します
  int get_height() const { return height; }

  // 幅を取得します
  int get_width() const { return width; }

  // i行目を取得します
  const std::string &operator[](int i) const {
    ASSERT_MSG(0 < i && i < height, "範囲外アクセスをしようとしています");
    return board[i];
  }

  // 現在のGridを90度回転させたGridを構築します
  Grid rotate_counterclockwise() const {
    std::vector<std::string> arg(width);
    for (int i = 0; i < width; i++) {
      for (int j = 0; j < height; j++) {
        arg[i].push_back(board[j][width - 1 - i]);
      }
    }
    return Grid(width, height, arg);
  }

  // 標準入力からGridを構築します
  // height個のstringが入力されることを期待します。そうでない場合の動作は未定義です
  static Grid create(int height, int width) {
    std::vector<std::string> arg(height);
    for (int i = 0; i < height; i++) {
      std::cin >> arg[i];
      ASSERT_MSG((int)arg[i].length() == width, "想定と幅が異なります");
    }
    return Grid(height, width, arg);
  }

private:
  int height;
  int width;
  std::vector<std::string> board;

  friend std::ostream &operator<<(std::ostream &out, const Grid &grid) {
    out << "---BEGIN---" << std::endl;
    for (int i = 0; i < grid.height; i++) {
      out << grid[i] << std::endl;
    }
    out << "----END----";
    return out;
  }
};

#endif
