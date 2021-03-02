#include "leetcode.h"

#define pii pair<int, int>

// Dijkstra
class Solution
{
public:
  int reachableNodes(vector<vector<int>>& edges, int M, int N)
  {
    vector<vector<pii>> graph(N);
    for (vector<int> edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      graph[u].push_back({ v, w });
      graph[v].push_back({ u, w });
    }

    map<int, int> dist;
    dist[0] = 0;
    for (int i = 1; i < N; ++i)
      dist[i] = M + 1;

    map<pii, int> used;
    int ans = 0;

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    pq.push({ 0, 0 });

    while (!pq.empty()) {
      pii top = pq.top();
      pq.pop();
      int d = top.first, node = top.second;
      if (d > dist[node])
        continue;
      dist[node] = d;

      // Each node is only visited once.  We've reached
      // a node in our original graph.
      ans++;

      for (auto pair : graph[node]) {
        // M - d is how much further we can walk from this node;
        // weight is how many new nodes there are on this edge.
        // v is the maximum utilization of this edge.
        int nei = pair.first;
        int weight = pair.second;
        used[{ node, nei }] = min(weight, M - d);

        // d2 is the total distance to reach 'nei' (neighbor) node
        // in the original graph.
        int d2 = d + weight + 1;
        if (d2 < min(dist[nei], M + 1)) {
          pq.push({ d2, nei });
          dist[nei] = d2;
        }
      }
    }

    // At the end, each edge (u, v, w) can be used with a maximum
    // of w new nodes: a max of used[u, v] nodes from one side,
    // and used[v, u] nodes from the other.
    for (vector<int> edge : edges) {
      int u = edge[0], v = edge[1], w = edge[2];
      ans += min(w, used[{ u, v }] + used[{ v, u }]);
    }
    return ans;
  }
};

// bfs
class Solution2
{
public:
  // edges[i]: [ [u_i, v_i, cnt_i]... ]
  // maxMove = M
  // num of vertices: N
  int reachableNodes(vector<vector<int>>& edges, int M, int N)
  {
    vector<vector<pair<int, int>>> graph(N);
    for (const auto& e : edges) {
      auto u = e[0], v = e[1], w = e[2];
      graph[u].emplace_back(v, w);
      graph[v].emplace_back(u, w);
    }
    queue<pair<int, int>> q; // (node, remaining steps)
    map<int, int> st;        // steps left at a node (always favour more left)
    q.push({ M, 0 });        // node 0; left M
    while (!q.empty()) {
      auto p = q.front();
      auto remain = p.first;
      auto node = p.second;
      q.pop(); // front is destroyed
      if (st.count(node) && st[node] > remain)
        continue; // visited and takes less steps
      st[node] = remain;
      for (const auto& nei : graph[node]) {
        auto next = nei.first;
        auto weight = nei.second;
        auto x = remain - weight - 1;
        if (x < 0 || (st.count(next) && st[next] > x))
          continue;
        q.push({ x, next });
      }
    }
    int ans = st.size();
    for (const auto& e : edges) {
      int uv = st.count(e[0]) ? st[e[0]] : 0;
      int vu = st.count(e[1]) ? st[e[1]] : 0;
      ans += min(uv + vu, e[2]);
    }
    return ans;
  }
};

// Dijkstra's algorithm using priority queue
class Solution3
{
public:
  int reachableNodes(vector<vector<int>>& edges, int M, int N)
  {
    // pair: weight, node
    vector<vector<pair<int, int>>> g(N);
    for (const auto& e : edges) {
      g[e[0]].emplace_back(e[1], e[2]);
      g[e[1]].emplace_back(e[0], e[2]);
    }

    priority_queue<pair<int, int>> pq; // max heap
    pq.emplace(M, 0);                  // node 0, M steps left
    vector<int> steps_left(N, 0);
    vector<bool> settled(N, false);

    while (!pq.empty()) {
      const auto u = pq.top().second;
      const auto s = pq.top().first; // `s` steps left at node `u`
      pq.pop();
      // the priority queue is doing the relaxation here, pair with more steps
      // left will be selected first. Once it is selected, it is settled. Later
      // pairs with the same node will be disgarded
      if (settled[u]) // u is settled
        continue;
      settled[u] = true;
      steps_left[u] = s;
      for (const auto& vw : g[u]) {
        // u --> v : w
        const auto v = vw.first;
        const auto w = vw.second;
        auto s_ = s - w - 1; // steps left at v
        if (s_ < 0)          // unreachable from u
          continue;
        if (!settled[v]) {
          // might deprecates the previously enqueued pair for node `v`
          // solution: use set as priority_queue
          pq.emplace(s_, v);
        }
      }
    }

    int ans = accumulate(settled.begin(), settled.end(), 0);
    for (const auto& e : edges) {
      // u = e[0], v = e[1],
      ans += min(e[2], steps_left[e[0]] + steps_left[e[1]]);
    }
    return ans; // if this is to find the shortest path
  }
};

// Dijkstra's algorithm, using set as priority queue
class Solution4
{
public:
  int reachableNodes(vector<vector<int>>& edges, int M, int N)
  {
    // pair: weight, node
    vector<vector<pair<int, int>>> g(N);
    for (const auto& e : edges) {
      g[e[0]].emplace_back(e[1], e[2]);
      g[e[1]].emplace_back(e[0], e[2]);
    }

    set<pair<int, int>, greater<pair<int, int>>> pq; // descending order
    pq.emplace(M, 0);                                // node 0, M steps left
    vector<int> steps_left(N, -1);                    // current state
    steps_left[0] = M;
    vector<bool> settled(N, false);

    while (!pq.empty()) {
      const auto u = pq.begin()->second; // steps_left[u]
      pq.erase(pq.begin());
      if (settled[u])
        continue;
      settled[u] = true;
      for (const auto& vw : g[u]) {
        // u --> v : w
        const auto v = vw.first;
        const auto w = vw.second;
        auto s_ = steps_left[u] - w - 1; // steps left at v
        if (s_ < 0)                      // unreachable from u
          continue;

        // if (steps_left[v] < s_ || (steps_left[v] == 0 && !settled[v])) {
        // this if block is for initializing steps_left to 0
        // }
        // steps_left is initilized to zero
        if (steps_left[v] < s_ ) {
          pq.erase({ steps_left[v], v });
          steps_left[v] = s_;
          pq.emplace(s_, v);
        }
      }
    }

    int ans = accumulate(settled.begin(), settled.end(), 0);
    for (const auto& e : edges) {
      // u = e[0], v = e[1],
      ans += min(e[2],
                 max(0, steps_left[e[0]]) + // if unsettled: steps_left[v] == 0
                 max(0, steps_left[e[1]]));
    }
    return ans; // if this is to find the shortest path
  }
};
