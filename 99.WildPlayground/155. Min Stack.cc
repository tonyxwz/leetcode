#include "leetcode.h"

class MinStack
{
private:
  struct Node
  {
    int val_;
    int min_;
    Node* next_;

    Node(int val)
      : val_(val)
      , min_(val)
      , next_(nullptr)
    {}

    Node(int val, Node* next)
      : val_(val)
      , min_(min(val, next->min_))
      , next_(next)
    {}
  };

public:
  /** initialize your data structure here. */
  MinStack()
    : head_(nullptr)
  {}

  void push(int val)
  {
    if (head_) {
      head_ = new Node(val, head_);
    } else {
      head_ = new Node(val);
    }
  }

  void pop()
  {
    Node* bk = head_;
    head_ = head_->next_;
    delete bk;
  }

  int top() { return head_->val_; }

  int getMin() { return head_->min_; }

private:
  Node* head_;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */