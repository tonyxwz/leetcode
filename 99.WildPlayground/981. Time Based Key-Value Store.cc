#include "leetcode.h"
class TimeMap
{
public:
  /** Initialize your data structure here. */
  TimeMap() {}

  void set(string key, string value, int timestamp)
  {
    m[key].push_back({ timestamp, value });
  }

  string get(string key, int timestamp)
  {
    const auto& s = m[key];
    if (s.empty())
      return "";
    auto cmp = [&](int time, const pair<int, string>& p) -> bool {
      return time < p.first;
    };
    auto it = upper_bound(s.cbegin(), s.cend(), timestamp, cmp);
    if (it == s.cbegin()) // all of timestamps are larger
      return "";
    else
      return (it - 1)->second;
  }

private:
  unordered_map<string, vector<pair<int, string>>> m;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */
