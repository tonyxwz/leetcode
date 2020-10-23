#include <unordered_set>
#include <vector>

using namespace std;

/* Given an undirected graph, return true if and only if it is bipartite. */

/* Recall that a graph is bipartite if we can split its set of nodes into two
 * independent subsets A and B, such that every edge in the graph has one node
 * in A and another node in B. */

/* The graph is given in the following form: graph[i] is a list of indexes j for
 * which the edge between nodes i and j exists.  Each node is an integer between
 * 0 and graph.length - 1.  There are no self edges or parallel edges: graph[i]
 * does not contain i, and it doesn't contain any element twice. */

class Solution
{
public:
  bool isBipartite(vector<vector<int>>& graph)
  {
    vector<int> colors(graph.size());
    for (int i = 0; i < graph.size(); ++i)
      if (!colors[i])
        if (!paint(i, 1, graph, colors))
          return false;
    return true;
  }

private:
  bool paint(int node,
             int color,
             const vector<vector<int>>& graph,
             vector<int>& colors)
  {
    if (colors[node])
      return colors[node] == color;
    colors[node] = color;
    for (const int i : graph[node])
      if (!paint(i, color == 1 ? 2 : 1, graph, colors))
        return false;
    return true;
  }
};
