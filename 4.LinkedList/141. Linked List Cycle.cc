// https://leetcode.com/problems/linked-list-cycle/
#include "leetcode.h"

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
    bool hasCycle(ListNode *head) {
        // fast slow pointer
        auto fast = head;
        auto slow = head;
        while(fast) {
            if (!fast->next) return false;
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) return true;
        }
        return false;
    }
};
// ```

