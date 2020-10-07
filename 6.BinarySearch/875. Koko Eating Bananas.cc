#include "leetcode.h"
// https://leetcode.com/problems/koko-eating-bananas/
// TODO 思考什么时候二分搜索给出lower bound和upper bound

// 二分查找有几种写法？它们的区别是什么？ - Jason Li的回答 - 知乎
// https://www.zhihu.com/question/36132386/answer/530313852

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int l = 1;
        int r = *max_element(piles.begin(), piles.end()) + 1; // not including r
        while (l < r) {
            int m = l + (r - l) / 2;
            int hours = 0;
            for (auto x:piles)
                hours += (x + m - 1) / m;
            if (hours <= H) { // 如果hours小于H，那么可以每小时再少吃一点，让hours大一点
                r = m;
            } else { // 不能在H小时内吃完香蕉，需要增加m
                l = m + 1;
            }
        }
        return l;
    }
};