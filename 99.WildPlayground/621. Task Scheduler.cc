#include "leetcode.h"

// Note: Greedy. always try to schedule the most frequent tasks first
class Solution
{
public:
  int leastInterval(vector<char>& tasks, int n)
  {
    vector<int> count(26);
    int maxNum = 0;
    for (auto c : tasks) {
      count[c - 'A']++;
      maxNum = max(maxNum, count[c - 'A']);
    }
    int units = (maxNum - 1) * (n + 1);

    for (auto i : count)
      if (i == maxNum)
        units++;
    return units < tasks.size() ? tasks.size() : units;
  }
};

// follow up: try to give an arrangement plan
// clear solution, also greedy
class Solution
{
public:
  int leastInterval(vector<char>& tasks, int n)
  {
    unordered_map<char, int> counter;
    for (auto c : tasks)
      counter[c]++;
    priority_queue<pair<int, char>> pq;
    for (const auto& p : counter)
      pq.push({ p.second, p.first });

    const int cycle = n + 1;
    int tot = 0;
    while (!pq.empty()) {
      int cyc = 0;
      vector<pair<int, char>> tmp;
      for (int i = 0; i < cycle; ++i) {
        if (!pq.empty()) {
          tmp.push_back(pq.top());
          pq.pop();
        }
      }
      cyc = tmp.size();
      for (auto& p : tmp) {
        if (--p.first)
          pq.push(p);
      }
      tot += (pq.empty() ? cyc : cycle);
    }
    return tot;
  }
};