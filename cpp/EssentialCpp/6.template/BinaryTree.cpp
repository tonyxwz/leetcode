#include <new>
#include <utility>
/* Class template BinaryTree:
 * public api:
 *    - insert
 *    - remove
 *    - find
 *
 * iterator class:
 *    - inorder
 *    - preorder
 *    - postorder
 */

// P.S. this is how to solve this requirement loop
template<typename T>
class BinaryTree; // forward declaration

template<typename T>
class BTNode // {{{

{
  // Remember this line:
  // Collaborative class relationships often require friendship.
  // Allowing the Binary tree class's access to private members
  friend class BinaryTree<T>;
  friend void copy(const BTNode<T>& src, BTNode<T>& tgt)
  {
    tgt->_val = src->_val;
    tgt->_lchild = src->_lchild;
    tgt->_rchild = src->_rchild;
  }
  friend void swap(BTNode& a, BTNode& b)
  {
    using std::swap;
    swap(a._val, b._val);
    swap(a._lchild, b._lchild);
    swap(a._rchild, b._rchild);
  }

public:
  BTNode(const T& val);
  bool insert_value(const T& val);
  void lchild_leaf(BTNode* leaf, BTNode* subtree);

private:
  T _val; // actual value
  // within the definition of a class template, the class name doesn't need to
  // be qualified.
  BTNode<T>* _lchild; // left child
  BTNode<T>* _rchild; // right child
  int _cnt;           // number of occurance
};

template<typename T>
inline BTNode<T>::BTNode(const T& val)
  : _val(val) // parameter initialization list, _val copy constructed directly
              // instead of constuct then copy assigned
{
  _cnt = 1;
  _lchild = _rchild = nullptr;
}

// insert to the node or child node
template<typename T>
inline bool
BTNode<T>::insert_value(const T& val)
{
  if (this->_val == val) {
    ++this->_cnt;
    return false;
  } else if (this->_val < val) {
    if (!this->_lchild) {
      this->_lchild = new BTNode<T>(val);
      return true;
    } else
      return this->_lchild->insert_value(val);
  } else {
    if (!this->_rchild) {
      this->_rchild = new BTNode<T>(val);
      return true;
    } else
      return this->_rchild->insert_value(val);
  }
}
template<typename T>
void
BTNode<T>::lchild_leaf(BTNode* leaf, BTNode* subtree)
{
  while (subtree->_lchild) {
    subtree = subtree->_lchild;
  }
  subtree->_lchild = leaf;
}
// }}}

template<typename T>
class BinaryTree // {{{
{
  friend void swap(BinaryTree& a, BinaryTree& b)
  {
    using std::swap;
    swap(a._root, b._root);
  }

public:
  BinaryTree();
  BinaryTree(const BinaryTree& other);
  ~BinaryTree();
  BinaryTree& operator=(BinaryTree other)
  {
    swap(*this, other); // copy and swap
    return *this;
  }
  bool empty() const { return _root == nullptr; }
  void clear() { delete _root; }

public:
  bool find();
  void insert(const T& val);

private:
  // BTNode need to be qualified in class template BinaryTree
  BTNode<T>* _root;
  void _destroy(
    BTNode<T>& node); // free all resources (still needed?? given clear)
};

template<typename T>
BinaryTree<T>::BinaryTree()
  : _root(nullptr)
{}

template<typename T>
BinaryTree<T>::BinaryTree(const BinaryTree& other)
{
  copy(other, *this);
}

template<typename T>
BinaryTree<T>::~BinaryTree()
{
  clear();
}
template<typename T>
inline void
BinaryTree<T>::insert(const T& val)
{
  if (!_root)
    _root = new BTNode<T>(val);
  else
    _root->insert_value(val);
}
template<typename T>
bool
BinaryTree<T>::find()
{
  return false;
}
// }}}
