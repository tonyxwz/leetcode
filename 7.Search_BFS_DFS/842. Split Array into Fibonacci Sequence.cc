#include <functional>
#include <string>
#include <vector>

using namespace std;
class Solution
{
public:
  vector<int> splitIntoFibonacci(string S)
  {
    const int n = S.length();
    vector<int> nums;

    function<bool(int)> dfs = [&](int pos) {
      if (pos == n)
        return nums.size() >= 3;
      int max_len = S[pos] == '0' ? 1 : 10;
      long num = 0;
      for (int i = pos; i < min(pos + max_len, n); ++i) {
        num = num * 10 + S[i] - '0';
        // this is important since num is long type
        if (num > INT_MAX) break;
        if (nums.size() >= 2) {
          long sum = nums.rbegin()[0];
          sum += nums.rbegin()[1];
          if (num > sum)
            break;
          else if (num < sum)
            continue;
          // num == sum
        }
        nums.push_back(num);
        if (dfs(i + 1))
          return true;
        nums.pop_back();
      }
      return false;
    };
    dfs(0);
    return nums;
  }
};
