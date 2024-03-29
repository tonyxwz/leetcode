// https://leetcode.com/problems/merge-k-sorted-lists/submissions/
#include "leetcode.h"
// TODO Priority queue  https://en.wikipedia.org/wiki/Priority_queue

// ```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
// linear scan O(n * k)
class Solution
{
public:
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    ListNode head;
    ListNode* curr = &head;

    while (true) {
      int ind = -1;
      for (int i = 0; i < lists.size(); ++i) {
        if (lists[i]) {
          if (ind > -1) {
            if (lists[i]->val < lists[ind]->val) {
              ind = i;
            }
          } else {
            ind = i;
          }
        }
      }
      if (ind > -1) {
        curr->next = lists[ind];
        lists[ind] = lists[ind]->next;
        curr = curr->next;
      } else {
        break;
      }
    }

    return head.next;
  }
};
// ```

// Divide and conquer method

// ```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution
{
public:
  ListNode* mergeKLists(vector<ListNode*>& lists)
  {
    if (lists.size() == 0)
      return nullptr;
    int N = lists.size();
    int interval = 1;
    // Reminder!!: nice interval design
    while (interval < N) {
      cout << interval;
      for (int i = 0; i < N - interval; i += interval * 2) {
        lists[i] = merge2Lists(lists[i], lists[i + interval]);
      }
      interval *= 2;
    }
    return lists[0];
  }

  ListNode* merge2Lists(ListNode* l1, ListNode* l2)
  {
    ListNode head;
    ListNode* curr = &head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        curr->next = l1;
        l1 = l1->next;
      } else {
        curr->next = l2;
        l2 = l2->next;
      }
      curr = curr->next;
    }
    if (l1)
      curr->next = l1;
    if (l2)
      curr->next = l2;
    return head.next;
  }
};
// ```

class Solution3
{
  // using heap (priority queue to find the minimal pointer)
  struct CompareNode
  {
    bool operator()(ListNode* a, ListNode* b) { return a->val < b->val; }
  };
  static bool compareNode(ListNode* a, ListNode* b) { return a->val < b->val; }

public:
  ListNode* mergeKList(vector<ListNode*>& lists)
  {
    priority_queue<ListNode*, vector<ListNode*>, CompareNode> pq(lists.begin(),
                                                                 lists.end());
    ListNode dummyhead;
    ListNode* curr = &dummyhead;
    while (!pq.empty()) {
      auto node = pq.top();
      pq.pop();
      curr->next = node;
      curr = curr->next;
      if (node->next)
        pq.push(node->next);
    }
    return dummyhead.next;
  }
};