#include "leetcode.h"

class Solution
{
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
  {
    set<int> a(nums1.begin(), nums1.end()), b(nums2.begin(), nums2.end());
    vector<int> result(min(a.size(), b.size()));
    auto it =
      set_intersection(a.begin(), a.end(), b.begin(), b.end(), result.begin());
    result.resize(it - result.begin());
    return result;
  }
};

// without using hash table, O(1) space complexity and O(n) time complexity
class Solution2
{
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2)
  {
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    int l1 = 0, l2 = 0;
    vector<int> out;
    while (l1 < nums1.size() && l2 < nums2.size()) {
      int x1 = nums1[l1], x2 = nums2[l2];
      if (x1 == x2) {
        out.push_back(x1);
        while (l1 < nums1.size() && nums1[l1] == x1)
          l1++;
        while (l2 < nums2.size() && nums2[l2] == x2)
          l2++;
        continue;
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