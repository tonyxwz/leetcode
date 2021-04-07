#include "leetcode.h"

class Solution
{
public:
  int findRadius(vector<int>& houses, vector<int>& heaters)
  {
    int ans = 0;
    sort(heaters.begin(), heaters.end());
    for (int i = 0; i < houses.size(); ++i) {
      auto house = houses[i];
      auto it = lower_bound(heaters.begin(), heaters.end(), house);
      // *it >= house
      if (it == heaters.begin())
        ans = max(ans, *it - house);
      else if (it == heaters.end())
        ans = max(ans, -*(it - 1) + house);
      else
        ans = max(ans, min(*it - house, -*(it - 1) + house));
    }
    return ans;
  }
};
