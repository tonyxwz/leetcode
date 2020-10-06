/* In binary search or any efficient search algorithm, the core issue is to
  reduce the search scope. Binary search reduces the search scope by half
  in each iteration.

  When trying to apply binary search, keep this in mind.
 */
#include <vector>
using namespace std;
class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      // cout in c++ slowes down the algorithm a lot
      // cout << l << "," << r << " " << nums[m] << endl;
      if (nums[l] < nums[m]) {
        // strictly middle is in the first array
        if (target < nums[m] && target > nums[l]) {
          r = m;
        } else if (target > nums[m] || target < nums[l]) {
          l = m + 1;
        } else {
          return true;
        }
      } else if (nums[l] > nums[m]) {
        // very sure that middle is in the second array
        if (target > nums[m] && target < nums[l]) {
          l = m + 1;
        } else if (target < nums[m] || target > nums[l]) {
          r = m;
        } else {
          return true;
        }

      } else {
        // not sure where mid lies if *mid == *l
        if (target == nums[l]) return true;
        l = l + 1;
      }
    }
    return false;
  }
};