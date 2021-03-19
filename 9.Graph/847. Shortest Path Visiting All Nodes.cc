#include "leetcode.h"

// BFS, think of pairs of (current node, visited nodes) as "node" in the virtual
// graph

class Solution
{
public:
  int shortestPathLength(vector<vector<int>>& graph)
  {
    const int N = graph.size();
    const int mask_ans = (1 << N) - 1;
    queue<pair<int, int>> q; // head, visited
    for (int i = 0; i < N; ++i)
      q.emplace(i, 1 << i); // only one visited
    unordered_set<int> visited;
    auto keygen = [](int node, int state) -> int {
      return (node << 15) | state;
    };

    int steps = 0;
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int head = q.front().first;
        int state = q.front().second;
        if (state == mask_ans)
          return steps;
        q.pop();
        int key = keygen(head, state);
        if (visited.count(key))
          continue;
        visited.insert(key);
        for (const int i : graph[head])
          q.emplace(i, state | (1 << i));
      }
      steps++;
    }
    return -1;
  }
};

class Solution2
{
public:
  int shortestPathLength(vector<vector<int>>& graph)
  {
    const int N = graph.size();
    const int mask_ans = (1 << N) - 1;
    queue<pair<int, int>> q; // head, visited
    for (int i = 0; i < N; ++i)
      q.emplace(i, 1 << i); // only one visited
    vector<vector<int>> visited(N, vector<int>(1 << N, 0));
    int steps = 0;
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int head = q.front().first;
        int state = q.front().second;
        if (state == mask_ans)
          return steps;
        q.pop();

        if (visited[head][state])
          continue;
        visited[head][state] = 1;
        for (const int i : graph[head])
          q.emplace(i, state | (1 << i));
      }
      steps++;
    }
    return -1;
  }
};
