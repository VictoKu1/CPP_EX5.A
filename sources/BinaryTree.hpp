#pragma once
#include <map>
#include <ostream>
using namespace std;
namespace ariel {
enum Side { Left, Right };
template <typename T> class BinaryTree {
private:
  class Node {
  public:
    Node *parent;
    Node *left;
    Node *right;
    T data;
    Node(const T &data) {
      parent = nullptr;
      left = nullptr;
      right = nullptr;
      (*this).data = data;
    }
    ~Node() {}
  };

private:
  Node *root;
  map<T, Node> nodeMap;

public:
  class Iterator {
  private:
    Node *pos;
    Iterator *next;

  public:
    Iterator() {
      pos = nullptr;
      next = nullptr;
    }
    ~Iterator() {}
    void operator=(const Iterator &that) {
      //*TODO.
      return;
    }
    bool operator==(const Iterator &that) {
      //*TODO.
      return false;
    }
    bool operator!=(const Iterator &that) { 
      //*TODO.
      return true; }
    const T &operator*() const {
      //*TODO.
      return (*pos).data;
    }
    Iterator operator++() {
      //*TODO.
      return (*this);
    }
    Iterator operator++(int) {
      //*TODO.
      return (*this);
    }
    Iterator operator--() {
      //*TODO.
      return (*this);
    }
    Iterator operator--(int) {
      //*TODO.
      return (*this);
    }
    T *operator->() { return new T((*pos).data); }
  };

public:
  BinaryTree() {
    //*TODO.
  }
  ~BinaryTree() {
    //*TODO.
  }
  BinaryTree<T> add_root(T newRoot) {
    //*TODO.
    //   if (root == nullptr) {
    //     root = new Node(newRoot);
    //     nodeMap.at(newRoot) = (*root);
    //     return (*this);
    //   }
    //   nodeMap.erase((*root).data);
    //   (*root).data = newRoot;
    //   nodeMap.at(newRoot) = (*root);
    return (*this);
  }
  BinaryTree<T> add_left(T pos, T newLeft) {
    //*TODO.
    //   if (nodeMap.count(pos) == 0) {
    //     throw invalid_argument{"No source node were found."};
    //   }
    //   insert(nodeMap.at(pos), newLeft, Left);
    return (*this);
  }
  BinaryTree<T> add_right(T pos, T newRight) {
    //*TODO.
    //   if (nodeMap.count(pos) == 0) {
    //     throw invalid_argument{"No source node were found."};
    //   }
    //   insert(nodeMap.at(pos), newRight, Right);
    return (*this);
  }
  Iterator begin_preorder() {
    Iterator i;
    return i;
  }
  Iterator end_preorder() {
    Iterator i;
    return i;
  }
  Iterator begin_inorder() {
    Iterator i;
    return i;
  }
  Iterator end_inorder() {
    Iterator i;
    return i;
  }
  Iterator begin_postorder() {
    Iterator i;
    return i;
  }
  Iterator end_postorder() {
    Iterator i;
    return i;
  }

  Iterator begin() {
    //*TODO.
    Iterator itr;
    return itr;
  }

  Iterator end() {
    //*TODO.
    Iterator itr;
    return itr;
  }

  friend ostream &operator<<(ostream &os, const BinaryTree<T> &root) {
    return os;
  }

private:
  void insert(Node n, T value, Side side) {
    //*TODO.
    switch (side) {
    case Left:
      if (n.left == nullptr) {
        n.left = new Node(value);
        nodeMap.at(value) = n.left;
        return;
      }
      nodeMap.erase(n.left->data);
      (*n.left).data = value;
      nodeMap.at(value) = n.left;
      break;
    case Right:
      if (n.right == nullptr) {
        n.right = new Node(value);
        nodeMap.at(value) = n.right;
        return;
      }
      nodeMap.erase(n.right->data);
      (*n.right).data = value;
      nodeMap.at(value) = n.right;
      break;
    }
  }
};
} // namespace ariel
