// https://leetcode.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ans = nullptr;
        ListNode** curr = &ans;
        bool forward = false;
        while(l1 && l2 || forward) {
            int sum = (l1 ? l1->val : 0 ) + (l2 ? l2->val : 0);
            if (forward) ++sum;
            *curr = new ListNode(sum % 10);
            forward = sum >= 10;
            curr = &(*curr)->next;
            if(l1) l1 = l1->next;
            if(l2) l2 = l2->next;
        }
        if (l1) *curr = l1;
        if (l2) *curr = l2;
        return ans;
    }
};
// ```