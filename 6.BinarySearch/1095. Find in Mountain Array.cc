#include "leetcode.h"

// reminder: 同样的道理，有些时候只要仔仔细细把所有的情况考虑清楚就可以了
// 一些数组下标的小技巧：
// 二分搜索，右侧下标选择off-edge end iterator 避免陷入死循环
// https://blog.csdn.net/weixin_42116347/article/details/104855353

/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */
class MountainArray {
 public:
  int get(int index);
  int length();
};

class Solution {
 public:
  int findInMountainArray(int target, MountainArray &mountainArr) {
    int peak = findPeak(mountainArr);
    cout << peak << endl;
    int l = searchAscending(target, 0, peak, mountainArr);
    if (l != -1) return l;
    int r = searchDescending(target, peak, mountainArr.length(), mountainArr);
    if (r != -1) return r;
    return -1;
  }

  int findPeak(MountainArray &mont) {
    int l = 0, r = mont.length() - 1;
    while (l < r) {
      int m = l + (r - l) / 2;
      int mid = mont.get(m);
      if (mid < mont.get(m + 1)) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return l;
  }

  int searchAscending(int target, int l, int r, MountainArray &arr) {
    while (l < r) {
      int m = l + (r - l) / 2;
      int mid = arr.get(m);
      if (mid == target) {
        return m;
      } else if (mid > target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return -1;
  }

  int searchDescending(int target, int l, int r, MountainArray &arr) {
    while (l < r) {
      int m = l + (r - l) / 2;
      int mid = arr.get(m);
      if (mid == target) {
        return m;
      } else if (mid > target) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return -1;
  }
};