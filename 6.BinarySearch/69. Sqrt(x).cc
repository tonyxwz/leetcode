#include "leetcode.h"

class Solution {
public:
    int mySqrt(int x) {
        long l = 1;
        long r = static_cast<long>(x) + 1;
        while (l < r) {
            long m = l + (r-l) / 2;
            if (m * m > x) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        return l - 1;
    }
};

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0)
            return 0;
        int l = 1, r = x;
        while(l <= r) {
            int mid = l + (r - l) / 2;
            int x_ = x / mid;
            if (x_ < mid)
                r = mid - 1;
            else if (x_ > mid)
                l = mid + 1;
            else
                return mid;
        }
        return r;
    }
};