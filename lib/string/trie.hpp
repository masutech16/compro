#include <memory>
#include <string>
#include <vector>
using namespace std;

#ifndef TRIE_TREE
#define TRIE_TREE

template <int word_size, char base> class Trie {
  class Node {
  public:
    // ancestorsNumは自分自身を含む数にしておく
    Node(int v) : val(v), isEnd(false), children(0), ancestorsNum(0) {}

    // 挿入に成功したらtrueを返す(既に入っていたりしたらfalse)
    bool insert(const std::string &str, int index) {
      int length = str.length();
      if (length == index) {
        if (isEnd) {
          return false;
        }
        ancestorsNum++;
        return isEnd = true;
      }

      int next_val = str[index] - base;
      for (const auto &child : children) {
        if (child->getVal() == next_val) {
          if (child->insert(str, index + 1)) {
            ancestorsNum++;
            return true;
          } else {
            return false;
          }
        }
      }
      // なければ作る
      children.emplace_back(new Node(next_val));
      if (children.back()->insert(str, index + 1)) {
        ancestorsNum++;
        return true;
      }
      return false;
    }

    bool search(const std::string &str, int index) const {
      int length = str.length();
      if (length <= index) {
        return isEnd;
      }
      int next_val = str[index] - base;
      for (const auto &child : children) {
        if (child->getVal() == next_val) {
          child->serach(str, index + 1);
        }
      }
      return false;
    }

    int countPrefix(const std::string &str, int index) const {
      int length = str.length();
      if (length <= index) {
        return true;
      }
      int next_val = str[index] - base;
      for (const auto &child : children) {
        if (child->getVal() == next_val) {
          child->serach(str, index + 1);
        }
      }
      return false;
    }

    int getAncestorsNum() const { return ancestorsNum; }

    int getVal() const { return val; }

  private:
    int val;
    bool isEnd;
    std::vector<std::unique_ptr<Node>> children;
    int ancestorsNum;
  };

public:
  Trie() : root(new Node(-1)) {}

  void insert(const std::string &str) { root->insert(str, 0); }

  bool search(const std::string &str) const { return root->search(str, 0); }

  int countPrefix(const std::string &prefix) const { return root->countPrefix(prefix, 0); }

  int size() const { return countPrefix(""); }

private:
  std::unique_ptr<Node> root;
};

#endif
