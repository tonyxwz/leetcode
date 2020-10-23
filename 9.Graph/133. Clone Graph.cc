/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution
{
public:
  Node* cloneGraph(Node* node)
  {
    if (!node)
      return nullptr;
    unordered_map<Node*, Node*> m;
    unordered_set<Node*> done;
    queue<Node*> q;
    q.push(node);
    while (!q.empty()) {
      Node* n = q.front();
      q.pop();
      if (done.count(n))
        continue;
      done.insert(n);
      if (!m.count(n))
        m[n] = new Node(n->val);
      for (Node* nn : n->neighbors) {
        if (!m.count(nn))
          m[nn] = new Node(nn->val);
        m[n]->neighbors.push_back(m[nn]);
        if (!done.count(nn))
          q.push(nn);
      }
    }
    return m[node];
  }
};
