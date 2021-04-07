#include "leetcode.h"

class Solution
{
public:
  int hIndex(vector<int>& citations)
  {
    int l = 0, r = citations.size();
    while (l < r) {
      int m = l + (r - l) / 2;
      int cits = citations[m];
      int n_pap = citations.size() - m;
      // requires cits >= n_pap
      if (cits < n_pap)
        l = m + 1;
      else
        r = m;
    }
    return citations.size() - l;
  }
};