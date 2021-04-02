#include "leetcode.h"

// Note: smart method

class Solution
{
public:
  int subarraySum(vector<int>& nums, int k)
  {
    // m[s] := how many sums up to s from head
    // if m[s-k]
    unordered_map<int, int> m;
    int count = 0, sum = 0;
    m[0] = 1;
    for (int i = 0; i < nums.size(); ++i) {
      sum += nums[i];
      if (m.count(sum - k))
        count += m.at(sum - k);
      m[sum] = m[sum] + 1;
    }
    return count;
  }
};