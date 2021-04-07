#include "leetcode.h"

// Note: Boyer–Moore majority vote algorithm
// How to remeber: two passes
// it can be generalized to k
// http://www.cs.rug.nl/~wim/pub/whh348.pdf
class Solution
{
public:
  vector<int> majorityElement(vector<int>& nums)
  {
    int x = 0, y = 0, cx = 0, cy = 0;
    for (const auto i : nums) {
      if (i == x)
        cx++;
      else if (i == y)
        cy++;
      else if (cx == 0)
        x = i, cx = 1;
      else if (cy == 0)
        y = i, cy = 1;
      else
        cx--, cy--;
    }
    cx = 0, cy = 0;
    for (const auto i : nums) {
      if (i == x)
        cx++;
      else if (i == y)
        cy++;
    }
    vector<int> ans;
    if (cx > nums.size() / 3)
      ans.push_back(x);
    if (cy > nums.size() / 3)
      ans.push_back(y);
    return ans;
  }
};