// https://leetcode.com/problems/add-two-numbers-ii/
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
        stack<int> s1;
        stack<int> s2;
        while(l1) {s1.push(l1->val); l1 = l1->next;};
        while(l2) {s2.push(l2->val); l2 = l2->next;};

        ListNode* ans = nullptr;
        bool forward = false;
        while(!s1.empty() || !s2.empty() || forward) {
            int s = 0;
            if (!s1.empty())
            {
                s+=s1.top();s1.pop();
            }
            if (!s2.empty()) {
                s+=s2.top();s2.pop();
            }
            if (forward) ++s;
            auto tmp = ans;
            ans = new ListNode(s % 10);
            ans->next = tmp;
            forward = s >= 10;
        }
        return ans;
    }
};
// ```