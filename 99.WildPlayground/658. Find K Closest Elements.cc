#include "leetcode.h"

class Solution
{
public:
  vector<int> findClosestElements(vector<int>& arr, int k, int x)
  {
    auto closer = [&](const int& a, const int& b) {
      int ax = abs(a - x);
      int bx = abs(b - x);
      if (ax < bx)
        return true;
      else if (ax > bx)
        return false;
      else // ax == bx
        return a < b;
    };
    sort(arr.begin(), arr.end(), closer);
    sort(arr.begin(), arr.begin() + k);
    return vector<int>(arr.begin(), arr.begin() + k);
  }
  // using binary search
  vector<int> findClosestElements(vector<int>& arr, int k, int x)
  {
    auto it = upper_bound(arr.begin(), arr.end(), x);
    if (it == arr.end()) // every element in arr is less than x
      return vector<int>(arr.end() - k, arr.end());
    if (it == arr.begin()) // every element in arr is larger than x
      return vector<int>(arr.begin(), arr.begin() + k);
    if (abs(*(it - 1) - x) < abs(*it - x))
      it = it - 1;
    auto l = it, r = it;
    int n = 0;
    while (n < k) {
      int nr = (r == arr.end() ? INT_MAX : abs(*r - x));
      int nl = (l == arr.begin() ? INT_MAX : abs(*(l - 1) - x));
      if (nl <= nr)
        l--;
      else
        r++;
      n++;
    }
    return vector<int>(l, r);
  }
};
