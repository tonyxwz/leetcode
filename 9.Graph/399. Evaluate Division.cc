#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution
{
public:
  vector<double> calcEquation(vector<vector<string>>& equations,
                              vector<double>& values,
                              vector<vector<string>>& queries)
  {
    /* 0: not marked, 1: solving, 2: solved */
    unordered_map<string, unordered_map<string, double>> m;
    for (int i = 0; i < equations.size(); ++i) {
      m[equations[i][0]][equations[i][1]] = values[i];
      m[equations[i][1]][equations[i][0]] = 1.0 / values[i];
    }

    vector<double> ans(queries.size(), -1);
    for (int i = 0; i < queries.size(); ++i) {
      const string& a = queries[i][0];
      const string& b = queries[i][1];
      if (!m.count(a) || !m.count(b))
        continue;
      unordered_set<string> visited;
      ans[i] = divide(a, b, m, visited);
    }
    return ans;
  }

private:
  double divide(const string& a,
                const string& b,
                const unordered_map<string, unordered_map<string, double>>& m,
                unordered_set<string>& visited)
  {
    if (a == b)
      return 1.0;
    visited.insert(a);
    // IMPORTANT: using operater[] requires mutable map
    for (const auto& pair : m.at(a)) {
      const string& c = pair.first;
      if (visited.count(c))
        continue;
      double mid = divide(c, b, m, visited);
      if (mid != -1.0)
        return mid * pair.second;
    }
    return -1.0;
  }
};

// Runtime: 3 ms
class Solution2
{
public:
  vector<double> calcEquation(vector<pair<string, string>> equations,
                              vector<double>& values,
                              vector<pair<string, string>> queries)
  {
    // g[A][B] = k -> A / B = k
    unordered_map<string, unordered_map<string, double>> g;
    for (int i = 0; i < equations.size(); ++i) {
      const string& A = equations[i].first;
      const string& B = equations[i].second;
      const double k = values[i];
      g[A][B] = k;
      g[B][A] = 1.0 / k;
    }

    vector<double> ans;
    for (const auto& pair : queries) {
      const string& X = pair.first;
      const string& Y = pair.second;
      if (!g.count(X) || !g.count(Y)) {
        ans.push_back(-1.0);
        continue;
      }
      unordered_set<string> visited;
      ans.push_back(divide(X, Y, g, visited));
    }
    return ans;
  }

private:
  // get result of A / B
  double divide(const string& A,
                const string& B,
                unordered_map<string, unordered_map<string, double>>& g,
                unordered_set<string>& visited)
  {
    if (A == B)
      return 1.0;
    visited.insert(A);
    for (const auto& pair : g[A]) {
      const string& C = pair.first;
      if (visited.count(C))
        continue;
      double d = divide(C, B, g, visited); // d = C / B
      // A / B = C / B * A / C
      if (d > 0)
        return d * g[A][C];
    }
    return -1.0;
  }
};
