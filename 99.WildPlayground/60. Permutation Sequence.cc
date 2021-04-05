#include "leetcode.h"

class Solution
{
public:
  string getPermutation(int n, int k)
  {
    int tot = factorial(n);
    k--;
    int used = 0;
    string ans;
    for (int i = n; i > 0; --i) {
      int blk = tot / i;
      int offset = k / blk;
      int j = 0;
      while (offset >= 0) {
        if (used & (1 << j++))
          continue;
        else
          offset--;
      }
      used = used | (1 << (j - 1));
      ans.push_back('0' + j);
      k = k % blk;
      tot = blk;
    }
    return ans;
  }

  string getPermutation2(int n, int k)
  {
    string ans;
    dfs(k - 1, n, 0, ans);
    return ans;
  }

  int factorial(int n)
  {
    if (n == 0)
      return 1;
    int ans = 1;
    for (int i = 1; i <= n; ++i)
      ans = ans * i;
    return ans;
  }

  // k: the k'th in this block,
  // n: no. of options in this block,
  // used: used bits
  void dfs(int k, int n, int used, string& ans)
  {
    if (n == 0)
      return;
    int blk = factorial(n - 1); // block size
    int offset = k / blk;       // unused number before this digit
    int i = 0;                  // current digit from '0'
    while (offset >= 0) {
      if (used & (1 << i++))
        continue;
      else
        offset--;
    }
    used = used | (1 << (i - 1));
    ans.push_back('0' + i);
    dfs(k % blk, n - 1, used, ans);
  }
};