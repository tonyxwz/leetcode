#include "leetcode.h"
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n+1, 0);
        dp[0] = 1;
        // dp[1] = 1;
        for(int i = 1;i <= n; ++i) {
            dp[i] = dp[i-1];
            if (i >= 2)
                dp[i] += dp[i-2];
        }
        return dp[n];
    }
};
