#include <vector>
#include <algorithm>
using namespace std;

class Solution1
{ // brute force
public:
  int trap(vector<int>& height)
  {
    auto sit = height.cbegin();
    auto eit = height.cend();
    int ans = 0;
    for (int i = 0; i < height.size(); i++) {
      ans +=
        min(max(*max_element(sit, sit + i + 1), *max_element(sit + i, eit))) -
        height[i];
    }
  }
};

class Solution2
{ // dynamic programming to save the cost of calculating max_element
  // in every iteration.
public:
  int trap(vector<int>& height)
  {
    const int n = height.size();
    vector<int> l(n, 0);
    vector<int> r(n, 0);
    for (int i = 0; i < n; i++) {
      if (i == 0)
        l[i] = height[i];
      else
        l[i] = max(l[i - 1], height[i]);
    }
    for (int i = n - 1; i >= 0; i--) {
      if (i == n - 1)
        r[i] = height[i];
      else
        r[i] = max(r[i + 1], height[i]);
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
      ans += min(l[i], r[i]) - height[i];
    }
    return ans;
  }
};

class Solution3
{
  // two pointers: save some extra space complexity by analyzing the DP solution
  // because every time l[i] and r[i] is required in the dp solution, it only
  // need the previous element.
  public:
    int trap(vector<int>& height) {
      const int n = height.size();
      if (n == 0) return 0;
      int max_l = height[0];
      int max_r = height[n-1];
      int l = 0, r = n-1;
      int ans = 0;
      while(l < r) {
        if (max_l < max_r) {
          // if max_l < max_r, then the water trapped in height[l] is only
          // determined by max_l.
          ans += max_l - height[l];
          max_l = max(max_l, height[++l]);
        } else {
          ans += max_r - height[r];
          max_r = max(max_r, height[--r]);
        }
      }
      return ans;
    }
};

