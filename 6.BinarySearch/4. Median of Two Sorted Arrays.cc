// https://leetcode.com/problems/median-of-two-sorted-arrays/
#include "leetcode.h"

class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    const int n1 = nums1.size();
    const int n2 = nums2.size();
    // ?
    if (n1 > n2) return findMedianSortedArrays(nums2, nums1);
    // +1 对于除以2的影响：
    //      若本来刚好能整除则不变
    //      若本来不能整除则向上取整 （即对于尺寸为奇数的数组取正中间的元素,
    //      个数，下标是k-1
    int k = (n1 + n2 + 1) / 2;
    int l = 0, r = n1;
    // 上界为n1，当l取到n1时不能进入循环，所以不会造成数组越界
    while (l < r) {
      int m1 = l + (r - l) / 2;
      int m2 = k - m1;
      // nums1[m1]之前共有m1+1个元素，所以只需要在第二个数组中取m2-1个元素即可
      if (nums1[m1] < nums2[m2 - 1]) {
        // 说明nums[m1]比目标中位数小
        l = m1 + 1;
      } else {
        r = m1;
      }
    }
    // 这里的m1和m2是元素个数
    const int m1 = l;
    const int m2 = k - m1;
    // 取两个下限中较大的作为左中位数
    int c1 = max(m1 <= 0 ? INT_MIN : nums1[m1 - 1],
                 m2 <= 0 ? INT_MIN : nums2[m2 - 1]);

    if ((n1 + n2) % 2) return c1;
    // 如果是偶数，取两个上限中较小的作为右中位数
    int c2 =
        min(m1 >= n1 ? INT_MAX : nums1[m1], m2 >= n2 ? INT_MAX : nums2[m2]);
    return (c1 + c2) * 0.5;
  }
};