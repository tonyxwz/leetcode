#include "leetcode.h"
#include <random>
#include <chrono>

class Solution
{
public:
  bool isSubsequence(const string& s, const string& t)
  {
    size_t i = 0, j = 0;
    while (i < s.length() && j < t.length()) {
      if (s[i] == t[j])
        i++, j++;
      else
        j++;
    }
    return i == s.length();
  }
  Solution(const string& t)
  {
    // do this exactly once per target
    for (int i = 0, n = t.length(); i < n; ++i)
      idx_[t[i]].push_back(i);
  }
  bool followUp(const string& s)
  {
    int pre = 0;
    for (const auto c : s) {
      auto it = lower_bound(idx_[c].begin(), idx_[c].end(), pre);
      if (it == idx_[c].end())
        return false;
      // cout << c << " " << *it << endl;
      pre = *it + 1;
    }
    return true;
  }

private:
  unordered_map<char, vector<int>> idx_;
};

int
main()
{
  int count = 10000000;
  vector<string> S;
  std::minstd_rand0 g1(0);

  while (count--) {
    int length = g1() % 25 + 5;
    string s_;
    while (length--) {
      char c = 'a' + (g1() % 26);
      s_.push_back(c);
    }
    // cout << s_ << endl;
    S.push_back(s_);
  }
  string t = "wweraerwebasercaerdsasrwereraerwebasercaerdsasrwer";
  Solution sol(t);
  vector<int> res1, res2;

  auto StartTime1 = std::chrono::system_clock::now();
  for (int i = 0; i < S.size(); ++i) // const auto& s : S)
    if (sol.followUp(S[i]))
      res1.push_back(i);
  // cout << s << " is substring of " << t << endl;

  auto StartTime2 = std::chrono::system_clock::now();

  for (int i = 0; i < S.size(); ++i)
    if (sol.isSubsequence(S[i], t))
      res2.push_back(i);
  // cout << s << " is substring of " << t << endl;
  auto StartTime3 = std::chrono::system_clock::now();

  auto t1 = std::chrono::duration_cast<std::chrono::milliseconds>(StartTime2 -
                                                                  StartTime1)
              .count();
  auto t2 = std::chrono::duration_cast<std::chrono::milliseconds>(StartTime3 -
                                                                  StartTime2)
              .count();
  cout << "Naive:\t " << t2 << endl;
  cout << "Optimized:\t " << t1 << endl;

  if (res1 == res2)
    cout << res1.size() << " subsequences discovered" << endl;
  else {
    cout << "results don't match " << res1.size() << " vs " << res2.size()
         << endl;
  }
  return 0;
  ;
}