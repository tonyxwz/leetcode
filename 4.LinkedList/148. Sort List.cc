// https://leetcode.com/problems/sort-list/
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
    ListNode* sortList(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode* mid = getMid(head);
        ListNode* l = sortList(head);
        ListNode* r = sortList(mid);
        return merge(l, r);
    }

    ListNode* getMid(ListNode* head) {
        if (!head || !head->next) return nullptr;
        ListNode *slow = nullptr;
        ListNode *fast = head;
        while(fast && fast->next) {
            slow = (slow==nullptr? fast : slow->next);
            fast = fast->next->next;
        }
        ListNode* mid = slow->next;
        slow->next = nullptr;
        return mid;
    }

    ListNode* merge(ListNode* l, ListNode* r) {
        ListNode dh;
        ListNode *curr = &dh;
        while(l && r) {
            if (l->val < r->val) {
                curr->next = l;
                l = l->next;
            } else {
                curr->next = r;
                r = r->next;
            }
            curr = curr->next;
        }
        if (l) curr->next = l;
        if (r) curr->next = r;
        return dh.next;
    }
};
// ```