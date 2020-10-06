// https://leetcode.com/problems/linked-list-cycle-ii/
#include "leetcode.h"

// Floyd-Warshall algorithm TODO (Graph theory)
// https://en.wikipedia.org/wiki/Floyd%E2%80%93Warshall_algorithm

// Two pointers, fast and slow
// ```cpp
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head)
  {
    if(!head || !head->next) return nullptr;
    ListNode* fast = head;
    ListNode* slow = head;
    while(fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (fast == slow) {
        break;
      }
    }
    if (fast == slow) {
        slow = head;
        while(slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
    }
    return nullptr;
  }
};
// ```