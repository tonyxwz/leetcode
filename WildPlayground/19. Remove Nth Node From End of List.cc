#include "leetcode.h"

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
  ListNode* removeNthFromEnd(ListNode* head, int n)
  {
    ListNode dummy(0, head);
    ListNode* a = &dummy;
    ListNode* b = dummy.next;
    ListNode* c = &dummy;
    while (n--) {
      c = c->next;
    }
    while (c->next) {
      c = c->next;
      b = b->next;
      a = a->next;
    }

    a->next = b->next;
    return dummy.next;
  }
};