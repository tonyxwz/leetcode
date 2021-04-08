#include "leetcode.h"
// Greedy
class Solution
{
public:
  bool checkPalindromeFormation(string a, string b)
  {
    return check(a, b) || check(b, a);
  }
  bool check(const string& a, const string& b)
  {
    const int n = a.length();
    int i = 0, j = n - 1;
    while (i < j && a[i] == b[j]) {
      i++, j--;
    }
    if (isPalindrome(a, i, j) || isPalindrome(b, i, j))
      return true;
    return false;
  }
  bool isPalindrome(const string& s, int i, int j)
  {
    while (i < j) {
      if (s[i] != s[j])
        return false;
      i++, j--;
    }
    return true;
  }
};