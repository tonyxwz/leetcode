// https://leetcode.com/problems/reverse-linked-list/
#include "leetcode.h"

/* # Recursion
Reminder:
tail = reverseList(head->next);
the base condition is the last node, where `node->next=nullptr`

the reverse node->next and node
*/

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
class Solution {
public:

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        } else {
            auto tail = reverseList(head->next);
            head->next->next = head;
            head->next = nullptr;
            return tail;
        }
    }
};
// ```