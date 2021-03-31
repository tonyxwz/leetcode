#include "leetcode.h"

class Trie
{
private:
  // Node doesn't matter, edges are the chars
  class Node
  {
    friend class Trie;
    vector<Node*> links;
    bool isEnd;
    Node()
      : links{ vector<Node*>(26, nullptr) }
      , isEnd{ false }
    {}
    ~Node()
    {
      for (auto n : links)
        delete n;
    }
  };

  Node* root_;

public:
  /** Initialize your data structure here. */
  Trie()
    : root_{ new Node() }
  {}
  ~Trie() { delete root_; }

  /** Inserts a word into the trie. */
  void insert(string word)
  {
    auto node = root_;
    for (const auto c: word) {
      if (!node->links[c - 'a'])
        node->links[c - 'a'] = new Node();
      node = node->links[c - 'a'];
    }
    node->isEnd = true;
  }

  /** Returns if the word is in the trie. */
  bool search(string word)
  {
    auto node = root_;
    for (const auto c: word) {
      if (!node->links[c - 'a'])
        return false;
      node = node->links[c - 'a'];
    }
    return node->isEnd;
  }

  /** Returns if there is any word in the trie that starts with the given
   * prefix. */
  bool startsWith(string prefix)
  {
    auto node = root_;
    for (const auto c: prefix) {
      if (!node->links[c - 'a'])
        return false;
      node = node->links[c - 'a'];
    }
    return true;
  }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */