#include "leetcode.h"

class Solution {
  const vector<vector<char>> data = {{' '},           {},
                                     {'a', 'b', 'c'}, {'d', 'e', 'f'},
                                     {'g', 'h', 'i'}, {'j', 'k', 'l'},
                                     {'m', 'n', 'o'}, {'p', 'q', 'r', 's'},
                                     {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};

  void dfs(string digits, int l, string &curr, vector<string> &ans) {
    if (digits.length() == l) {
      ans.push_back(curr);
      return;
    }
    for (const char &c : data[digits[l] - '0']) {
      curr.push_back(c);
      dfs(digits, l + 1, curr, ans);
      curr.pop_back();
    }
  }

  vector<string> dfsWrapper(string digits) {
    if (digits.empty()) return {};
    string curr;
    vector<string> ans;
    dfs(digits, 0, curr, ans);
    return ans;
  }

  vector<string> bfs(string digits) {
    if (digits.empty()) return {};
    vector<string> ans{""};
    for (const char digit : digits) {
      vector<string> tmp;
      for (char c : data[digit - '0']) {
        for (string s : ans) {
          tmp.push_back(s + c);
        }
      }
      ans.swap(tmp);
    }
    return ans;
  }

 public:
  vector<string> letterCombinations(string digits) { return bfs(digits); }
};
