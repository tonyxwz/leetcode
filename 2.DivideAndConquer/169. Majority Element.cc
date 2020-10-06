// https://leetcode.com/problems/majority-element/
#include "leetcode.h"

class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    return dnd1(nums, 0, nums.size() - 1);
  }

  int dnd1(vector<int>& nums, int l, int r) {
    if (l == r) return nums[l];
    int m = l + (r - l) / 2;
    int ml = dnd1(nums, l, m);
    int mr = dnd1(nums, m + 1, r);
    if (ml == mr)
      return ml;
    else {
      return count(nums.begin() + l, nums.begin() + r + 1, ml) >
                     count(nums.begin() + l, nums.begin() + r + 1, mr)
                 ? ml
                 : mr;
    }
  }

  int partialSorting(vector<int>& nums) {
    nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
    return nums[nums.size() / 2];
  }

  int sorting(vector<int>& nums) {
    std::sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
  }

  int bitVoting(const vector<int>& nums) {
    int b = sizeof(nums[0]) * 8;
    int ans = 0;
    for (int i = 0; i < b; i++) {
      int mask = 1 << i;
      int n = nums.size() / 2;
      int count = 0;
      for (auto j : nums) {
        j = j & mask;
        if (j) {
          ++count;
          if (count > n) ans |= mask;
          break;
        }
      }
    }
    return ans;
  }

  int mooreVoting(vector<int>& nums) {
    int ans = nums.front();
    int count = 0;
    for (auto i : nums) {
      if (i == ans) {
        count++;
      } else if (--count == 0) {
        count = 1;
        ans = i;
      }
    }
    return ans;
  }

  // 茴香豆的第一种写法 stl map (red black tree)
  int RBT(vector<int>& nums) {
    map<int, int> m;
    int n = nums.size() / 2;

    for (auto a : nums) {
      if (n < ++m[a]) return a;
    }
    return -1;
  }

  // unorder_map hash table
  int hashTable(vector<int>& nums) {
    unordered_map<int, int> m;
    int n = nums.size() / 2;
    for (auto a : nums) {
      if (n < ++m[a]) return a;
    }
    return -1;
  }
};