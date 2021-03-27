#pragma once

#include <algorithm>
#include <deque>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <bitset>

using namespace std;

class Node
{
public:
  int val;
  vector<Node*> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node*> _children)
  {
    val = _val;
    children = _children;
  }
};

struct ListNode
{
  int val;
  ListNode* next;
  ListNode()
    : val(0)
    , next(nullptr)
  {}
  ListNode(int x)
    : val(x)
    , next(nullptr)
  {}
  ListNode(int x, ListNode* next)
    : val(x)
    , next(next)
  {}
};
struct TreeNode
{
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode()
    : val(0)
    , left(nullptr)
    , right(nullptr)
  {}
  TreeNode(int x)
    : val(x)
    , left(nullptr)
    , right(nullptr)
  {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
    : val(x)
    , left(left)
    , right(right)
  {}
};
