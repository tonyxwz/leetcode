#include "leetcode.h"

// solution 1 dfs

class Solution
{
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K)
  {
    vector<vector<vector<int>>> g(N + 1);
    vector<int> t(N, INT_MAX);
    for (const auto& t : times)
      g[t[0]].push_back({ t[1], t[2] });

    dfs(K, g, t, 0);
    int ans = *max_element(t.begin(), t.end());
    return ans == INT_MAX ? -1 : ans;
  }

private:
  void dfs(int u, vector<vector<vector<int>>>& g, vector<int>& t, int curr)
  {
    if (curr >= t[u - 1])
      return;
    t[u - 1] = curr;
    for (const auto& v : g[u]) {
      // going from u -> v[0] : v[1]
      dfs(v[0], g, t, curr + v[1]);
    }
  }
};

// Dijkstra algorithm

class Solution3
{
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K)
  {
    unordered_map<int, vector<vector<int>>> g;
    for (const auto& time : times)
      g[time[0]].push_back({ time[1], time[2] });

    priority_queue<pair<int, int>> pq;
    // priority-queue in stl is max heap by default, in dijkstra algorithm
    // we need a min heap instead
    // (two ways, negate distance or use std::greater)
    pq.push({ 0, K });
    vector<int> dist(N, 0);
    unordered_set<int> seen;

    while (!pq.empty()) {
      const auto p = pq.top();
      pq.pop();
      const auto u = p.second; // current node
      const auto d = -p.first; // distance from source
      if (seen.count(u))       // already visited node u
        continue;
      seen.insert(u); // visit node u
      dist[u - 1] = d;
      for (const auto& vw : g[u]) {
        const int v = vw[0];
        const int w = vw[1];
        if (!seen.count(v)) // problem: not as much pruning as solution5
          pq.push({ -d - w, v });
      }
    }
    return seen.size() == N ? *max_element(dist.begin(), dist.end()) : -1;
  }
};

#define MAX 101
#define PII pair<int, int>
#define pb push_back

class Solution4
{
public:
  vector<PII> adj[MAX]; // C++ array of vectors
  int dist[MAX];

  void dijkstra(int sv, int n)
  {
    for (int i = 1; i <= n; i++)
      dist[i] = INT_MAX;
    set<PII> pq;
    dist[sv] = 0; // set initial dist
    pq.insert({ 0, sv });

    while (!pq.empty()) {
      int curr = pq.begin()->second;
      int d = pq.begin()->first;
      pq.erase(pq.begin());

      if (dist[curr] < d)
        continue; // no use

      for (PII pr : adj[curr]) {
        int v = pr.first;
        int nd = d + pr.second;
        if (nd < dist[v]) {
          pq.erase({ dist[v], v });
          dist[v] = nd;
          pq.insert({ nd, v });
        }
      }
    }
  }

  int networkDelayTime(vector<vector<int>>& times, int N, int K)
  {
    int sz = times.size();
    int f, s, w;

    for (int i = 0; i <= N; i++)
      adj[i].clear();

    for (int i = 0; i < sz; i++) {
      f = times[i][0];
      s = times[i][1];
      w = times[i][2];
      adj[f].pb({ s, w }); // directed graph
    }

    dijkstra(K, N);

    int ans = INT_MIN;
    for (int i = 1; i <= N; i++) {
      if (dist[i] == INT_MAX)
        return -1; // unreachable point
      ans = max(ans, dist[i]);
    }
    return ans;
  }
};

class Solution5
{
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K)
  {
    unordered_map<int, vector<pair<int, int>>> g;
    for (const auto& time : times)
      g[time[0]].push_back({ time[1], time[2] });

    // priority_queue<pair<int, int>> pq;
    // pq.push({0, K});
    vector<int> dist(N + 1, INT_MAX);
    set<pair<int, int>> pq;
    pq.insert({ 0, K });
    dist[K] = 0;

    while (!pq.empty()) {
      const auto u = pq.begin()->second; // current node
      const auto d = pq.begin()->first;  // distance from source
      pq.erase(pq.begin());

      if (dist[u] < d) // no use
        continue;

      for (const auto& vw : g[u]) {
        const int v = vw.first;
        const int d_ = d + vw.second;
        if (d_ < dist[v]) {
          pq.erase({ dist[v], v });
          pq.insert({ d_, v });
          dist[v] = d_;
        }
      }
    }

    int ans = INT_MIN;
    for (int i = 1; i < dist.size(); i++) {
      if (dist[i] == INT_MAX)
        return -1;
      ans = max(ans, dist[i]);
    }

    return ans;
  }
};

// bellman ford
class Solution6
{
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K)
  {
    vector<int> dist(N, INT_MAX);
    dist[K - 1] = 0;

    for (int _i = 1; _i < N; _i++) {
      for (const auto& time : times) {
        // i -> j
        int u = time[0] - 1, v = time[1] - 1, w = time[2];
        if (dist[u] == INT_MAX)
          continue;
        dist[v] = min(dist[v], dist[u] + w);
      }
    }
    int max_dist = *max_element(begin(dist), end(dist));
    return max_dist == INT_MAX ? -1 : max_dist;
  }
};

// floyd-warshall
class Solution7
{
public:
  int networkDelayTime(vector<vector<int>>& times, int N, int K)
  {
    vector<vector<int>> dist(N, vector<int>(N, INT_MAX));
    for (auto t : times)
      dist[t[0] - 1][t[1] - 1] = t[2];
    for (int i = 0; i < N; i++)
      dist[i][i] = 0;

    for (int m = 0; m < N; m++) {
      for (int i = 0; i < N; i++) {
        if (i == m || dist[i][m] == INT_MAX)
          continue;
        for (int j = 0; j < N; j++) {
          if (j == m || dist[m][j] == INT_MAX)
            continue;
          dist[i][j] = min(dist[i][j], dist[i][m] + dist[m][j]);
        }
      }
    }

    int ans = INT_MIN;
    for (int i = 0; i < N; i++)
      ans = max(ans, dist[K - 1][i]);
    return ans == INT_MAX ? -1 : ans;
  }
};