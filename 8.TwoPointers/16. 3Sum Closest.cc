#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution
{
public:
  int threeSumClosest(vector<int>& nums, int target)
  {
    const int N = nums.size();
    int diff = INT_MAX;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < N - 2; i++) {
      if (i > 0 && nums[i] == nums[i - 1])
        continue;
      int j = i + 1;
      int k = N - 1;
      while (j < k) {
        int sum = nums[i] + nums[j] + nums[k];
        if (sum == target) // nice pruning
          return sum;
        int d = sum - target;
        if (abs(d) < abs(diff))
          diff = d;
        if (sum < target)
          j++;
        else
          k--;
      }
    }
    return target + diff;
  }
};
