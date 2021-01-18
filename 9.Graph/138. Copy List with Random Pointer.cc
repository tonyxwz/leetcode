#include "leetcode.h"

// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
  Node *copyRandomList(Node *head)
  {
    if (!head) return head;
    unordered_map<Node*, Node*> m;
    Node* curr = new Node(head->val);
    m[head] = curr;
    Node* ans = curr;

    while(head) {
      if (head->next) {
        auto it = m.find(head->next);
        if (it == end(m))
          it = m.emplace(head->next, new Node(head->next->val)).first;
        curr->next = it->second;
      }

      if (head->random) {
        auto it = m.find(head->random);
        // emplace, returns a pair of (element, boolean)
        if (it == end(m))
          it = m.emplace(head->random, new Node(head->random->val)).first;
        curr->random = it->second;
      }
      curr = curr->next;
      head = head->next;
    }

    return ans;
  }
};
