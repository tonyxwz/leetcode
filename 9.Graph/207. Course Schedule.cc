#include <unordered_map>
#include <vector>
using namespace std;

/* Reminder: topological sorting
 */

class Solution
{
public:
  bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
  {
    vector<int> mark(numCourses, 0);
    vector<vector<int>> edges(numCourses);
    for(const auto& e: prerequisites)
      edges[e[0]].push_back(e[1]);
    for (int course = 0; course < numCourses; ++course)
      if (mark[course] == 0)
        if (dfs(course, edges, mark))
          return false;
    return true;
  }

private:
  int dfs(int x, vector<vector<int>>& edges, vector<int>& mark)
  {
    if (mark[x] == 1)
      return 1; // visiting: error
    if (mark[x] == 2)
      return 0; // visited: ok
    mark[x] = 1;
    for (const auto& e : edges[x])
      if (dfs(e, edges, mark))
        return 1;
    mark[x] = 2;
    return 0;
  }
};
