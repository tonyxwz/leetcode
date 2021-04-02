#include "leetcode.h"
// Note: greedy because it is guaranteed that there's a solution
class Solution
{
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people)
  {
    vector<vector<int>> q;

    auto cmp = [](const vector<int>& a, const vector<int>& b) {
      if (a[0] == b[0]) {
        return a[1] < b[1];
      } else {
        return a[0] > b[0];
      }
    };

    sort(people.begin(), people.end(), cmp);

    for (const auto& i : people) {
      q.insert(q.begin() + i[1], i);
    }
    return q;
  }
};
