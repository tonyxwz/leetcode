#include "leetcode.h"
class Solution
{
public:
  int maxProfit(vector<int>& prices)
  {
    int max_prof = 0;
    int min_value = INT_MAX;
    for (int i = 0; i < prices.size(); i++) {
      min_value = min(min_value, prices[i]);
      max_prof = max(max_prof, prices[i] - min_value);
    }
    return max_prof;
  }
};

