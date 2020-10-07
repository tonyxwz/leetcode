// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/
#include "leetcode.h"
// reminder
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int l = *max_element(weights.begin(), weights.end());
        int r = accumulate(weights.begin(), weights.end(), 0) + 1;
        while (l < r) {
            int m = l + (r - l) / 2;
            int days = 1;
            int cargo = 0;
            for(const auto& w:weights) {
                if ((cargo+=w) > m) {
                    cargo = w;
                    days++;
                }
            }
            if (days <= D) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l;
    }
};