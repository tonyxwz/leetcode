#include "leetcode.h"
struct TrieNode
{
public:
  TrieNode(const vector<string>& words)
    : TrieNode()
  {
    for (const auto& s : words)
      this->insert(s);
  }

  TrieNode()
    : is_end_{ false }
    , edges_{ vector<TrieNode*>(26, nullptr) }
    , s_(nullptr)
  {}

  ~TrieNode()
  {
    for (int i = 0; i < edges_.size(); ++i)
      if (edges_[i])
        delete edges_[i];
  }

  void insert(const string& s, int i = 0)
  {
    if (i == s.length()) {
      setEnd();
      s_ = &s;
      return;
    }
    if (edges_[s[i] - 'a'] == nullptr)
      edges_[s[i] - 'a'] = new TrieNode();
    edges_[s[i] - 'a']->insert(s, i + 1);
  }

  bool contains(const string& s, int i = 0)
  {
    if (i == s.length())
      return isEnd();
    if (edges_[s[i] - 'a'] == nullptr)
      return false;
    else
      return edges_[s[i] - 'a']->contains(s, i + 1);
  };

  bool isprefix(const string& s, int i = 0)
  {
    if (i == s.length())
      return true;
    if (edges_[s[i] - 'a'] == nullptr)
      return false;
    else
      return edges_[s[i] - 'a']->isprefix(s, i + 1);
  };
  bool isEnd() { return is_end_; };
  void setEnd() { this->is_end_ = true; }
  TrieNode* get(char c)
  {
    if (isalpha(c))
      return edges_[c - 'a'];
    else
      return nullptr;
  };
  const string& get() { return *s_; }

private:
  bool is_end_;
  vector<TrieNode*> edges_;
  const string* s_;
};

class Solution
{
public:
  vector<string> findWords(vector<vector<char>>& board, vector<string>& words)
  {
    auto root = new TrieNode(words);
    const int m = board.size(), n = board[0].size();

    vector<vector<bool>> used(m, vector<bool>(n, false));
    set<string> ans;

    function<void(int, int, TrieNode*)> dfs =
      [&](int i, int j, TrieNode* node) {
        if (!node)
          return;
        if (used[i][j])
          return;
        used[i][j] = true;
        if (node->isEnd())
          ans.insert(node->get());

        int dirs[5] = { 0, 1, 0, -1, 0 };

        for (int k = 0; k < 4; ++k) {
          int i_ = i + dirs[k];
          int j_ = j + dirs[k + 1];
          if (i_ < 0 || i_ >= m || j_ < 0 || j_ >= n)
            continue;
          dfs(i_, j_, node->get(board[i_][j_]));
        }
        used[i][j] = false;
      };

    for (int i = 0; i < m; ++i)
      for (int j = 0; j < n; ++j)
        if (root->get(board[i][j]))
          dfs(i, j, root->get(board[i][j]));
    delete root;
    return vector<string>(ans.begin(), ans.end());
  }
};
