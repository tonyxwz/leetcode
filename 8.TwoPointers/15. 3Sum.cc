#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
  vector<vector<int>> threeSum(vector<int>& nums)
  {
    const int N = nums.size(); // size_t -> int
    sort(nums.begin(), nums.end());
    vector<vector<int>> ans;
    for (int i = 0; i < N - 2; i++) {
      if (i > 0 && nums[i - 1] == nums[i])
        continue;
      const int target = -nums[i];
      int j = i + 1, k = N - 1;
      while (j < k) {
        if (nums[j] + nums[k] < target)
          j++;
        else if (nums[j] + nums[k] > target)
          k--;
        else {
          ans.push_back({ nums[i], nums[j], nums[k] });
          // not unique
          k--;
          while (j < k && nums[k] == nums[k + 1])
            k--;
        }
      }
    }
    return ans;
  }
};
