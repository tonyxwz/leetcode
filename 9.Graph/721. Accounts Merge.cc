#include "leetcode.h"

// solution 1 dfs;
// clearly the emails forms a graph, the first email in a account's list is
// treated as the principle email, which connects to every other email belonging
// to the same person.
// Traversal is done in DFS manner, process children, then neighbours.
class Solution
{
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
  {
    unordered_map<string, string> email_to_name;
    unordered_map<string, set<string>> graph;
    for (const auto& account : accounts) {
      const int n = account.size();
      const string name = account[0];
      for (int i = 1; i < n; i++) {
        email_to_name[account[i]] = name;
        graph[account[i]].insert(account[1]);
        graph[account[1]].insert(account[i]);
      }
    }
    unordered_set<string> seen;
    vector<vector<string>> ans;
    for (const auto& item : graph) {
      const string& email = item.first;
      if (!seen.count(email)) {
        seen.insert(email);
        stack<string> s;
        s.push(email);
        vector<string> components;
        while (!s.empty()) {
          string e = s.top();
          s.pop();
          components.push_back(e);
          for (const auto& c : graph.at(e)) {
            if (!seen.count(c)) {
              seen.insert(c);
              s.push(c);
            }
          }
        }
        sort(components.begin(), components.end());
        ans.push_back({ email_to_name[email] });
        ans.back().insert(
          ans.back().end(), components.begin(), components.end());
      }
    }
    return ans;
  }
};

// Solution 2 disjoint set
// finding the connected components of a graph is a nature fit for UFDS data
// structure.
class DisjointSet
{
private:
  vector<int> p;    // parents
  vector<int> rank; // rank

public:
  DisjointSet(const int N)
    : p(N)
    , rank(N, 0)
  {
    iota(p.begin(), p.end(), 0);
  }

  int find(const int x)
  {
    // path compression
    if (p[x] != x)
      p[x] = find(p[x]);
    return p[x];
  }

  int find2(int x)
  {
    while (p[x] != x) {
      p[x] = p[p[x]];
      x = p[x];
    }
    return x;
  }

  bool merge(const int a, const int b)
  {
    auto pa = find(a);
    auto pb = find(b);
    if (pa == pb)
      return false;
    if (rank[pa] < rank[pb])
      p[a] = pb;
    else if (rank[pa] > rank[pb])
      p[b] = pa;
    else {
      p[a] = pb;
      rank[pb]++;
    }
    return true;
  }
};

class Solution2
{
public:
  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts)
  {
    unordered_map<string, string> email_to_name;
    unordered_map<string, int> email_to_id;
    DisjointSet ds(10000);

    int i = 0;
    for (const auto& acc : accounts) {
      const string& name = acc[0];
      for (int j = 1; j < acc.size(); j++) {
        const string& email = acc[j];
        email_to_name[email] = name;
        if (!email_to_id.count(email))
          email_to_id[email] = i++;
        ds.merge(email_to_id[email], email_to_id[acc[1]]);
      }
    }

    unordered_map<int, vector<string>> m;
    for (const auto& pair : email_to_id) {
      const string& email = pair.first;
      m[ds.find(pair.second)].push_back(pair.first);
    }
    vector<vector<string>> ans;
    for (auto& pair : m) {
      sort(pair.second.begin(), pair.second.end());
      ans.push_back(pair.second);
      ans.back().insert(ans.back().begin(), email_to_name[ans.back()[0]]);
    }
    return ans;
  }
};
