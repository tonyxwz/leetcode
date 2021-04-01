#include "leetcode.h"

// Priority Queue
// In C++, Priority Queue can be implemented with `priority_queue` or multiset

class Solution
{
public:
  int findKthLargest(vector<int>& nums, int k)
  {
    priority_queue<int, vector<int>, greater<int>> pq;
    for (auto i : nums) {
      pq.push(i);
      if (pq.size() > k)
        pq.pop();
    }
    return pq.top();
  }
};
