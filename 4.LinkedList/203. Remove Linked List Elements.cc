// https://leetcode.com/problems/remove-linked-list-elements/
#include "leetcode.h"

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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode prev;
        prev.next = head;
        ListNode* ptr = &prev;
        while(ptr->next) {
            if (ptr->next->val == val) {
                ptr->next = ptr->next->next;
            } else
                ptr = ptr->next;
        }
        return prev.next;
    }
};
// ```