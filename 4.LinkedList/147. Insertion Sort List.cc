// https://leetcode.com/problems/insertion-sort-list/
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode dh;
        ListNode *curr, *tmp, *tmp2;
        while(head) {
            curr = &dh;
            while(curr->next && curr->next->val < head->val)
                curr = curr->next;
            tmp2 = head->next;

            tmp = curr->next;
            curr->next = head;
            head->next = tmp;

            head = tmp2;
        }
        return dh.next;
    }
};
// ```