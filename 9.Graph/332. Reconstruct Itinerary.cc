#include "leetcode.h"

class Solution
{
public:
  vector<string> findItinerary(vector<vector<string>>& tickets)
  {
    unordered_map<string, deque<string>> g;
    for (const auto& e : tickets)
      g[e[0]].push_back(e[1]);
    for (auto& p : g) {
      auto& dest = p.second;
      sort(dest.begin(), dest.end());
    }

    vector<string> ans;
    const string start = "JFK";
    visit("JFK", g, ans);
    reverse(ans.begin(), ans.end());
    return ans;
  }
  void visit(const string& name,
             unordered_map<string, deque<string>>& g,
             vector<string>& ans)
  {
    auto& dests = g[name];
    while (!dests.empty()) {
      const string name = dests.front();
      dests.pop_front();
      visit(name, g, ans);
    }
    ans.push_back(name);
  }
};