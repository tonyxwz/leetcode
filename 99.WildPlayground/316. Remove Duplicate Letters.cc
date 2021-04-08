#include "leetcode.h"

class Solution
{
public:
  string removeDuplicateLetters(string s)
  {
    vector<int> count(26, 0);
    for (auto c : s)
      count[c - 'a']++;
    vector<bool> visited(26, false);

    stack<char> st;

    for (auto c : s) {
      int i = c - 'a';
      count[i]--;
      if (visited[i])
        continue;
      visited[i] = true;

      // greedily check if there're characters to the right of current position
      while (!st.empty() && st.top() > c && count[st.top() - 'a'] > 0) {
        visited[st.top() - 'a'] = false;
        st.pop();
      }

      st.push(c);
    }
    deque<char> q;
    while (!st.empty())
      q.push_front(st.top()), st.pop();
    return string(q.begin(), q.end());
  }
};