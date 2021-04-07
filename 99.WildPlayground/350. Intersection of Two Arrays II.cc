#include "leetcode.h"

class Solution
{
public:
  vector<int> intersect(vector<int>& nums1, vector<int>& nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int l1 = 0, l2 = 0;
    vector<int> out;
    while (l1 < nums1.size() && l2 < nums2.size()) {
      int x1 = nums1[l1], x2 = nums2[l2];
      if (x1 == x2) {
        out.push_back(x1);
        l1++, l2++;
      } else if (x1 < x2) {
        while (l1 < nums1.size() && nums1[l1] < nums2[l2])
          l1++;
      } else { // x1 > x2
        while (l2 < nums2.size() && nums1[l1] > nums2[l2])
          l2++;
      }
    }
    return out;
  }
};