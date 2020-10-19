#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution
{
public:
  bool canPartitionKSubsets(vector<int>& nums, int k)
  {
    int tot = accumulate(nums.begin(), nums.end(), 0);
    if (tot % k)
      return false;

    sort(nums.rbegin(), nums.rend());
    // used = 0 because the question guarantees that the length of nums is less
    // than 16
    return search(nums, tot / k, 0, k, 0);
  }

private:
  bool search(const vector<int>& nums, int target, int cur, int k, int used)
  {
    if (k == 0) // every number is used
      return used == (1 << nums.size()) - 1;
    for (int i = 0; i < nums.size(); i++) {
      if (used & (1 << i))
        continue;
      int t = cur + nums[i];
      if (t > target)
        break;
      int new_used = used | (1 << i);
      if (t == target && search(nums, target, 0, k - 1, new_used))
        return true;
      else if (search(nums, target, t, k, new_used))
        return true;
    }
    return false;
  }
};

// Author: Huahua
// Running time: 4 ms (<99.21%)
class Solution2
{
public:
  bool canPartitionKSubsets(vector<int>& nums, int k)
  {
    const int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0)
      return false;
    sort(nums.rbegin(), nums.rend());
    return dfs(nums, sum / k, 0, k, 0);
  }

private:
  bool dfs(const vector<int>& nums, int target, int cur, int k, int used)
  {
    if (k == 0)
      return used == (1 << nums.size()) - 1;
    for (int i = 0; i < nums.size(); ++i) {
      if (used & (1 << i)) // 跳过已经使用过的数字
        continue;
      int t = cur + nums[i];
      if (t > target) // 如果当前的总和大于pile那么说明最后一个 nums[i]
                      // 对于当前的 pile 太大了 应该跳出尝试下一个组合
        break;                        // Important
      int new_used = used | (1 << i); //
      // finished one pile, then pile num--
      if (t == target && dfs(nums, target, 0, k - 1, new_used))
        return true;
      // still working on the first pile
      else if (dfs(nums, target, t, k, new_used))
        return true;
    }
    return false;
  }
};
