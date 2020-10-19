#include "leetcode.h"

class Solution
{
public:
  int openLock(vector<string>& deadends, string target)
  {
    unordered_set<string> deadCodes(deadends.begin(), deadends.end());
    unordered_set<string> visited{ "0000" };

    queue<string> q;
    if (!deadCodes.count("0000"))
      q.push("0000");

    const int L = 4;
    int step = 0;
    while (!q.empty()) {
      // level loop
      for (int size = q.size(); size > 0; size--) {
        string code = q.front();
        q.pop();
        if (code == target)
          return step;

        for (int i = 0; i < L; i++) {
          // up and down variants
          const char ch = code[i];
          for (int d = -1; d <= 1; d += 2) {
            code[i] = (ch + 10 + d - '0') % 10 + '0';
            if (deadCodes.count(code) || visited.count(code))
              continue;
            q.push(code);
            visited.insert(code);
          }
          code[i] = ch;
        }
      }
      step++;
    }
    return -1;
  }
};

class Solution2
{
public:
  int openLock(vector<string>& deadends, string target)
  {
    // TODO: Bidirectional BFS using integer
  }
};