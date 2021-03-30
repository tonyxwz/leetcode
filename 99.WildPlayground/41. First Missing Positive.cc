#include "leetcode.h"
class Solution
{
public:
  int firstMissingPositive(vector<int>& nums)
  {
    set<int> nums_(nums.begin(), nums.end());
    auto s = upper_bound(nums_.begin(), nums_.end(), 0);

    int missing = 1;
    for (; s != nums_.end(); ++s) {
      cout << *s << endl;
      if (*s != missing)
        break;
      missing++;
    }
    return missing;
  }
};