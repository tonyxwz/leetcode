#include "leetcode.h"
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        const auto range = minmax_element(nums.begin(), nums.end());
        const int l = *(range.first);
        const int r = *(range.second);

        vector<int> nums_(r-l+1, 0);
        for(const auto i: nums)
            nums_[i - l] += i;

        int dp = 0, dp1 = 0;
        for(const auto i: nums_) {
            int tmp = dp;
            dp = max(dp, dp1 + i);
            dp1 = tmp;
        }
        return dp;
    }
};