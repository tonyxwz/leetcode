#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using std::queue;
using std::string;
using std::unordered_map;
using std::unordered_set;
using std::vector;

class Solution
{
public:
  int minMutation(string start, string end, vector<string>& bank)
  {
    unordered_map<string, unordered_set<string>> g;
    for (int i = 0; i < bank.size(); i++) {
      const string& a = bank[i];
      for (int j = 0; j < bank.size(); j++) {
        const string& b = bank[j];
        if (g[b].count(a) || isMutation(a, b))
          g[a].insert(b);
      }
    }

    queue<string> q;
    q.push(start);
    unordered_set<string> visited;

    int step = 0;
    while (!q.empty()) {
      int size = q.size();
      while (size--) {
        const string& s = q.front();
        visited.insert(s);
        q.pop();
        if (s == end)
          return step;
        for (const string& c : g[s])
          if (!visited.count(c))
            q.push(c);
      }
      step++;
    }
    return -1;
  }

private:
  bool isMutation(const string& a, const string& b)
  {
    int diff = 0;
    for (int i = 0; i < 8; i++)
      diff += (a[i] != b[i]);
    return diff == 1;
  }
};
