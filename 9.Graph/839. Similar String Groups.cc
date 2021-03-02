#include "leetcode.h"
#include <numeric>

// Note: disjoint set doesn't guarantee that the number of different items
// in `parents_` equals the number of different groups. It only guarantees
// find(a) == find(b) if a and b should be in the same group. Hence, before
// calculating the number of groups, it is required to run find on all
// items.

class Disjointset
{
private:
  vector<int> parents_;
  vector<int> ranks_;

public:
  Disjointset(const vector<string>& strs)
    : parents_{ vector<int>(strs.size()) }
    , ranks_{ vector<int>(strs.size(), 0) }
  {
    iota(parents_.begin(), parents_.end(), 0);
  }

  int find(int i)
  {
    if (parents_[i] != i)
      parents_[i] = find(parents_[i]);
    return parents_[i];
  }

  bool union_(int a, int b)
  {
    int pa = find(a);
    int pb = find(b);
    if (pa == pb)
      return false;
    if (ranks_[pa] < ranks_[pb]) { // merge a to b
      parents_[pa] = pb;
    } else if (ranks_[pa] > ranks_[pb]) { // merge b to a
      parents_[pb] = pa;
    } else { // equal merge a to b
      parents_[pa] = pb;
      ranks_[pb]++;
    }
    return true;
  }

  int ngroups()
  {
    for (int i = 0, size = parents_.size(); i < size; ++i)
      find(i);
    set<int> s(this->parents_.begin(), this->parents_.end());
    return s.size();
  }
};

class Solution
{
public:
  int numSimilarGroups(vector<string>& strs)
  {
    Disjointset dj(strs);
    for (int i = 0; i < strs.size(); ++i) {
      for (int j = i + 1; j < strs.size(); ++j) {
        if (is_similar(strs[i], strs[j]))
          dj.union_(i, j);
      }
    }
    return dj.ngroups();
  }
  bool is_similar(const string& s1, const string& s2)
  {
    int diff[2] = { 0, 0 };
    int size = 0;
    for (int i = 0; i < s1.size(); ++i) {
      if (s1[i] != s2[i]) {
        if (size > 1)
          return false;
        diff[size++] = i;
      }
    }
    return size == 0 || (size == 2 && s1[diff[0]] == s2[diff[1]] &&
                         s1[diff[1]] == s2[diff[0]]);
  }
};
