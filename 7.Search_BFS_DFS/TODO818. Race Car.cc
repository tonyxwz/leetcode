#include "leetcode.h"


/* LeetCode: application framework

 */
struct State
{
  int position;
  int speed;
  State(int position, int speed)
    : position{ position }
    , speed{ speed }
  {}
};

// WRONG! Time out, learn DP
class Solution
{
public: 
  int racecar(int target)
  {
    queue<State> q;
    q.push(State(0, 1));
    int ans = 0;
    while (!q.empty()) {
      for (int size = q.size(); size > 0; size--) {
        const State s = q.front();
        q.pop();
        if (s.position == target)
          return ans;
        // 这里需要剪枝，否则解空间是质数增长
        // under what situation, we only need to consider 'A' or 'R'
        // s: current, s1: if 'A', s2: if 'R'
        State s1(s.position + s.speed, s.speed * 2);
        State s2(s.position, s.speed > 0 ? -1 : 1);
        if (s1.position <= target)
          q.push(s1);
        else
          q.push(s1);
          q.push(s2);
      }
      ans++;
    }
    return ans;
  }
};

int
main()
{
  Solution s;
  auto ans = s.racecar(400);
  cout << ans << endl;
}