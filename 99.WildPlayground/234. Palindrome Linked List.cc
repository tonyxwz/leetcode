#include "leetcode.h"

// Note: using recursion to act as a stack
class Solution1
{
public:
  bool isPalindrome(ListNode* head) { return checkHeadAndTail(head, head); }

  bool checkHeadAndTail(ListNode* tail, ListNode*& head)
  {
    if (tail == nullptr)
      return true;

    bool ans = checkHeadAndTail(tail->next, head) && head->val == tail->val;
    head = head->next;
    return ans;
  }
};

// Note: Fast Slow pointers to find the middle of linked list
class Solution2
{
public:
  bool isPalindrome(ListNode* head)
  {
    ListNode *s = head, *f = head;
    while (f != nullptr && f->next != nullptr) {
      s = s->next;
      f = f->next->next;
    }
    // s is now at the middle

    auto tail = reverse(s);
    bool ans = true;
    // cout << tail->val << endl;
    while (ans && tail) {
      ans = ans && tail->val == head->val;
      tail = tail->next;
      head = head->next;
    }
    return ans;
  }

  ListNode* reverse(ListNode* start)
  {
    ListNode* pre = nullptr;
    while (start) {
      ListNode* tmp = start->next;
      start->next = pre;
      pre = start;
      start = tmp;
    }
    return pre;
  }
};
