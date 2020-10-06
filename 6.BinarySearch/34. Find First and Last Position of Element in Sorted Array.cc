// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
/*
 */
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return searchRange(nums, target, 0, nums.size());
  }
  vector<int> searchRange(vector<int>& nums, int target, int l, int r) {
    if (l >= r) return {-1, -1};
    int mid = l + (r - l) / 2;
    if (nums[mid] > target) {
      return searchRange(nums, target, l, mid);
    } else if (nums[mid] < target) {
      return searchRange(nums, target, mid + 1, r);
    } else {
      vector<int> vl = searchRange(nums, target, l, mid);
      vector<int> vr = searchRange(nums, target, mid + 1, r);
      int newl = vl[0] == -1 ? mid : vl[0];
      int newr = vr[1] == -1 ? mid : vr[1];
      return {newl, newr};
    }
  }
};

class Solution2 {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    return {firstPos(nums, target), lastPos(nums, target)};
  }
private:
  int firstPos(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;      
      if (nums[m] >= target) {
        // 中间点等于target时向左进
        r = m;
      } else {
        l = m + 1;
      }
    }
    
    if (l == nums.size() || nums[l] != target) return -1;
    return l;
  }
 
  int lastPos(const vector<int>& nums, int target) {
    int l = 0;
    int r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;      
      if (nums[m] > target) {
        r = m;
      } else {
        // 中间点等于target的时候要向右找，所以能保证l一直走到最右边。
        l = m + 1;
      }
    }
    // l points to the first element this is greater than target.
    --l;        
    if (l < 0 || nums[l] != target) return -1;
    return l;
  }
};