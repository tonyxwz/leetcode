#include "leetcode.h"

class Solution
{
public:
  char nextGreatestLetter(vector<char>& letters, char target)
  {
    auto it = upper_bound(letters.begin(), letters.end(), target);
    char ans = it == letters.end() ? letters.front() : *it;
    return ans;
  }
};

class Solution
{
public:
  char nextGreatestLetter(vector<char>& letters, char target)
  {
    int l = 0, r = letters.size();

    while (l < r) {
      int m = l + (r - l) / 2;
      if (letters[m] <= target)
        l = m + 1;
      else
        r = m;
    }
    char ans = l == letters.size() ? letters.front() : letters[l];
    return ans;
  }
};