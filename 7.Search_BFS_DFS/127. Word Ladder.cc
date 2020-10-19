#include "leetcode.h"

class Solution
{
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    // BFS: at every step there's a multiple choices to make.
    // put these choices in a queue and handle them one by one.
    unordered_set<string> set(wordList.begin(), wordList.end());
    if (set.find(endWord) == set.end())
      return 0;

    const int N = beginWord.length();
    queue<string> q;
    q.push(beginWord);
    int step = 0;
    // at the beginnin of every while loop the queue contains the elements
    // for the current row.
    while (!q.empty()) {
      step++;
      // process elements in the row
      for (int i = q.size(); i > 0; i--) {
        string w = q.front();
        q.pop();
        for (int i = 0; i < N; i++) {
          char c = w[i]; // save a original copy
          for (char x = 'a'; x <= 'z'; x++) {
            w[i] = x;
            if (w == endWord)
              return step + 1;
            if (set.find(w) == set.end())
              continue;
            set.erase(w);
            q.push(w);
          }
          w[i] = c;
        }
      }
    }
    return 0;
  }
};

// Bidirectional BFS
// Reminder: 记住那个三角形的树状结构和钻石形状的两个三角形相向生长的形状
class Solution2
{
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList)
  {
    unordered_set<string> words(wordList.begin(), wordList.end());
    if (words.find(endWord) == words.end())
      return 0;
    unordered_set<string> l{ beginWord };
    unordered_set<string> r{ endWord };

    int step = 0;
    while (!l.empty() && !r.empty()) {
      step++;
      if (l.size() > r.size())
        l.swap(r); // always grow the smaller set
      unordered_set<string> tmp;
      for (string s : l) {
        for (int i = 0; i < s.length(); i++) {
          char bk = s[i];
          for (char c = 'a'; c <= 'z'; c++) {
            s[i] = c;
            if (r.find(s) != r.end())
              return step + 1;
            if (words.find(s) == words.end())
              continue;
            tmp.insert(s);
            words.erase(s);
          }
          s[i] = bk;
        }
      }
      l.swap(tmp);
    }
    return 0;
  }
};
