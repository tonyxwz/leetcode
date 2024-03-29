#include "leetcode.h"

class Solution
{
public:
  int maxProfit(vector<int>& prices)
  {
    int ans = 0;
    for (int i = 1, n = prices.size(); i < n; ++i) {
      if (prices[i] > prices[i - 1])
        ans += (prices[i] - prices[i - 1]);
    }
    return ans;
  }
};
