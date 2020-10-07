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
