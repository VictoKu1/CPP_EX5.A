#pragma once
#include <ostream>
using namespace std;
namespace ariel {
template <typename T> class BinaryTree {
private:
  class Node {
  public:
    Node *left;
    Node *right;
    T data;
    Node(Node *left, const T &data, Node *right)
        : left(left), data(data), right(right) {}
    Node(const T &data) { (*this) = Node(nullptr, data, nullptr); }
  };
  Node *root;
  int size;

public:
  BinaryTree() : root(nullptr) { size = 0; }
  ~BinaryTree() {}
  BinaryTree<T> add_root(T *newRoot);
  BinaryTree<T> add_left(T *newLeft);
  BinaryTree<T> add_right(T *newRight);
  //*TODO.
  //*begin_preorder().
  //*end_preorder().
  //*begin_inorder().
  //*end_inorder().
  //*begin_postorder().
  //*end_postorder().
  friend ostream &operator<<(ostream &os, const BinaryTree<T> &root);
};
} // namespace ariel


