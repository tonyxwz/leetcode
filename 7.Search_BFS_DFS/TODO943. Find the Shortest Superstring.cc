#include "leetcode.h"
// 问题的关键在于，面试的时候我不知道这道题应该使用BFS或者DFS来解决，那么怎么才能有这种判断
/*
Input: ["catg","ctaagt","gcta","ttca","atgcatc"]
Output: "gctaagttcatgcatc" */
class Solution
{
  void shortestSuperstring(string& curr, const string& next)
  {
    // magically expand curr to include next
  }
  void dfs(vector<string>& A,
           int s,
           string& curr,
           vector<bool>& included,
           string& ans)
  {
    if (A.size() == s) {
      if (ans.length()) {
        if (ans.length() > curr.length()) {
          ans.clear();
          ans.insert(ans.begin(), curr.begin(), curr.end());
        }
      } else {
        ans.insert(ans.begin(), curr.begin(), curr.end());
      }
      return;
    }
    // for ()
  }

public:
  string shortestSuperstring(vector<string>& A)
  {
    string ans;
    string curr;
    vector<bool> included(A.size(), false);
    int s = 0;
    dfs(A, 0, curr, included, ans);
    return ans;
  }
};