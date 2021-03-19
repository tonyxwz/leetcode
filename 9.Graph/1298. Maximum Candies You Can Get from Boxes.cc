#include "leetcode.h"

class Solution
{
public:
  int maxCandies(vector<int>& status,
                 vector<int>& candies,
                 vector<vector<int>>& keys,
                 vector<vector<int>>& containedBoxes,
                 vector<int>& initialBoxes)
  {
    const int n = status.size();
    vector<int> found(n);
    vector<int> has_key(status);

    queue<int> q;
    for (int i : initialBoxes) {
      found[i] = 1;
      if (status[i])
        q.push(i);
    }

    int ans = 0;
    while (!q.empty()) {
      int box = q.front();
      q.pop();
      ans += candies[box];
      for (const auto b : containedBoxes[box]) {
        found[b] = 1;
        if (has_key[b])
          q.push(b);
      }
      for (const auto b : keys[box]) {
        if (!has_key[b] && found[b])
          q.push(b);
        has_key[b] = 1;
      }
    }
    return ans;
  }
};
