#include "leetcode.h"

// regular
class Solution
{
public:
  int maxProfit(vector<int>& prices)
  {
    const int n = prices.size();
    vector<int> hold(n + 1), sold(n + 1), rest(n + 1);
    hold[0] = INT_MIN;
    sold[0] = rest[0] = 0;

    for (int i = 1; i <= n; ++i) {
      hold[i] = max(hold[i - 1], rest[i - 1] - prices[i - 1]);
      sold[i] = hold[i - 1] + prices[i - 1];
      rest[i] = max(rest[i - 1], sold[i - 1]);
    }
    max(sold.back(), rest.back());
  }
};

// reduce dimensions

class Solution2
{
public:
  int maxProfit(vector<int>& prices)
  {
    int hold = INT_MIN, sold = 0, rest = 0;

    for (const auto& i : prices) {
      int tmp = hold;
      hold = max(hold, rest - i);
      rest = max(rest, sold);
      sold = tmp + i;
    }

    return max(sold, rest);
  }
};