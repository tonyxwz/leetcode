#include "leetcode.h"

/* Note: put the two linked lists tail to head
  |AAAAAAAAA|BBBBBB|(NULL)
  |BBBBBB|AAAAAAAAA|(NULL)
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB)
  {
    auto p1 = headA, p2 = headB;
    while (p1 != p2) {
      if (p1)
        p1 = p1->next;
      else
        p1 = headB;
      if (p2)
        p2 = p2->next;
      else
        p2 = headA;
    }
    return p1;
  }
};