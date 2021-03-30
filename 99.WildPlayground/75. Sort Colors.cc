#include "leetcode.h"

class Solution
{
public:
  void sortColors(vector<int>& nums)
  {
    int p0 = 0, p1 = 0;
    for (int i = 0; i < nums.size(); ++i) {

      switch (nums[i]) {
        case 0:
          for (int j = i; j > p0; --j)
            nums[j] = nums[j - 1];
          nums[p0] = 0;
          p0++;
          p1++;
          break;
        case 1:
          for (int j = i; j > p1; --j)
            nums[j] = nums[j - 1];
          nums[p1] = 1;
          p1++;
          break;
        default:
          break;
      }
    }
  }
};