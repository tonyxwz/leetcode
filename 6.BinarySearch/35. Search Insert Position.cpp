/* easy, can be solve with either recursion or iteration
Note that it is easier to use l >= r as the boundary condition */
#include <vector>
using namespace std;


class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        return recursive(nums, 0, nums.size(), target);
    }
    
    int iterative(vector<int>& nums, int target) {
        int r = nums.size();
        int l = 0;
        while(l < r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
    
    int recursive(vector<int>& nums, int l, int r, int target) {
        if (l >= r ) return l;
        int mid = l + (r - l) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            return recursive(nums, mid+1, r, target);
        } else {
            return recursive(nums, l, mid, target);
        }
    }
};