#include "leetcode.h"

// You are given an array routes representing bus routes where routes[i] is a
// bus route that the ith bus repeats forever.

//     For example, if routes[0] = [1, 5, 7], this means that the 0th bus
//     travels in the sequence 1 -> 5 -> 7 -> 1 -> 5 -> 7 -> 1 -> ... forever.

// You will start at the bus stop source (You are not on any bus initially),
// and you want to go to the bus stop target. You can travel between bus stops
// by buses only.

// Return the least number of buses you must take to travel from source to
// target. Return -1 if it is not possible.

class Solution
{
public:
  int numBusesToDestination(vector<vector<int>>& routes, int source, int target)
  {
    unordered_map<int, vector<int>> m;
    for (int bus = 0, size = routes.size(); bus < size; ++bus)
      for (const auto stop : routes[bus])
        m[stop].push_back(bus);
    queue<int> q;
    vector<bool> visited(routes.size(), false);
    q.push(source);
    int step = 0;
    while (!q.empty()) {
      int qsize = q.size();
      while (qsize--) {
        int stop = q.front();
        q.pop();
        if (stop == target)
          return step;
        for(const auto bus: m[stop]) {
          if (visited[bus])
            continue;
          visited[bus] = true;
          for(const auto s: routes[bus]) {
            q.push(s);
          }
        }
      }
      ++step;
    }
    return -1;
  }
};