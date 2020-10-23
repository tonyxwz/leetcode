#include <vector>
using namespace std;

class Solution
{
public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites)
  {
    vector<vector<int>> edges(numCourses);
    for (const auto& p : prerequisites) {
      edges[p[0]].push_back(p[1]);
    }
    vector<int> ans;
    vector<int> marker(numCourses);
    for (int course = 0; course < numCourses; ++course)
      if (dfs(course, edges, ans, marker))
        return {};
    return ans;
  }

private:
  int dfs(int course,
          vector<vector<int>>& edges,
          vector<int>& ans,
          vector<int>& marker)
  {
    if (marker[course] == 1)
      return 1;
    if (marker[course] == 2)
      return 0;
    marker[course] = 1;
    for (const auto& c : edges[course])
      if (dfs(c, edges, ans, marker))
        return 1;
    ans.push_back(course);
    marker[course] = 2;
    return 0;
  }
};
