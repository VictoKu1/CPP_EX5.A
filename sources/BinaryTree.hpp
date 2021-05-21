#include "doctest.h"
#include <ostream>
using namespace std;
namespace ariel {
template <typename T> class BinaryTree {
private:
  BinaryTree<T> *root;
  BinaryTree<T> *left;
  BinaryTree<T> *right;
  T data;
  int size;
  int rightSize;
  int leftSize;

public:
  BinaryTree() {}
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