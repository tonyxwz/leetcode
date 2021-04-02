#include "leetcode.h"

// Note Worth reading official solution
class Solution
{
public:
  vector<int> topKFrequent(vector<int>& nums, int k)
  {
    unordered_map<int, int> m;
    for (auto i : nums)
      m[i]++;
    auto comp = [&m](int n1, int n2) { return m[n1] > m[n2]; };
    // how to use function as comparator
    priority_queue<int, vector<int>, function<bool(int, int)>> pq(comp);

    for (const auto& p : m) {
      pq.push(p.first);
      if (pq.size() > k)
        pq.pop();
    }
    vector<int> ans;
    while (!pq.empty()) {
      ans.push_back(pq.top());
      pq.pop();
    }
    return ans;
  }
};