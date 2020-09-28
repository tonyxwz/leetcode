#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;


class Solution {
 public:
  vector<int> sortArray(vector<int>& nums) {
    quickSort(nums, 0, nums.size());
    return nums;
  }

  int median(const int a, const int b, const int c) {
    if (a > b)
      if (b > c)
        return b;
      else if (c > a)
        return a;
      else
        return c;
    else if (a > c)
      return a;
    else if (c > b)
      return b;
    else
      return c;
  }

  void quickSort(vector<int>& nums, const int begin, const int end) {
    if (begin + 1 >= end) return;
    const int pivot = median(nums[begin], nums[end-1], nums[begin+(end-begin)/2]);
    // const int pivot = nums[end - 1];
    int l = begin;
    int r = end - 1;
    while (1) {
      while (nums[l] < pivot) {
        ++l;
      }
      while (pivot < nums[r]) {
        --r;
      }
      if (l >= r)
        break;
      else {
        int tmp = nums[l];
        nums[l] = nums[r];
        nums[r] = tmp;
        ++l;
        --r;
      }
    }
    quickSort(nums, begin, l);
    quickSort(nums, l, end);
  }
};


int main() {
  Solution s;
  vector<int> v{1, 1, 3, 2, 4, 1, 7, 8, 1, 2, 9, 10, 34, 3};
  s.quickSort(v, 0, v.size());
  cout << is_sorted(v.begin(), v.end()) << endl;
}