#include "leetcode.h"

class Solution
{
public:
  vector<int> partitionLabels(string S)
  {
    vector<int> last('z' - 'a' + 1, -1);
    const int n = S.length();
    for (int i = 0; i < n; ++i)
      last[S[i] - 'a'] = i;

    vector<int> ans;
    int pre = 0;
    int min_index = 0; // update along the way
    for (int i = 0; i < n; ++i) {
      min_index = max(min_index, last[S[i] - 'a']);
      if (i == min_index) {
        // cout << i << endl;
        ans.push_back(i - pre + 1);
        pre = min_index + 1;
      }
    }
    return ans;
  }
};