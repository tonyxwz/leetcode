#include "leetcode.h"

class Solution
{
public:
  string shortestSuperstring(vector<string>& words)
  {
    const int N = words.size();

    vector<vector<int>> g(N, vector<int>(N, 0));
    for (int i = 0; i < N; ++i)
      for (int j = 0; j < N; ++j) {
        g[i][j] = words[j].length();
        for (int k = 1; k < min(words[i].length(), words[j].length()); ++k) {
          // number of chars to add if j follows i
          if (words[i].substr(words[i].length() - k) == words[j].substr(0, k))
            g[i][j] = words[j].length() - k;
        }
      }

    vector<vector<int>> dp(1 << N, vector<int>(N, INT_MAX / 2));
    vector<vector<int>> parents(1 << N, vector<int>(N, -1));

    for (int i = 0; i < N; ++i)
      dp[1 << i][i] = words[i].length();

    for (int s = 1; s < (1 << N); ++s) { // currently visited words
      for (int tail = 0; tail < N; ++tail) {
        if (!(s & (1 << tail)))
          continue;                 // tail is not in s
        int pre = s & ~(1 << tail); // nodes without tail
        for (int mid = 0; mid < N; ++mid) {
          if (dp[pre][mid] + g[mid][tail] < dp[s][tail]) {
            dp[s][tail] = dp[pre][mid] + g[mid][tail];
            parents[s][tail] = mid;
          }
        }
      }
    }

    auto it = min_element(begin(dp.back()), end(dp.back()));
    int j = it - begin(dp.back());
    int s = (1 << N) - 1;
    string ans;
    while (s) {
      int i = parents[s][j];
      if (i < 0)
        ans = words[j] + ans;
      else {
        ans = words[j].substr(words[j].length() - g[i][j]) + ans;
      }
      s = s & (~(1 << j));
      j = i;
    }
    return ans;
  }
};

int
main()
{
  vector<string> input{ "catg", "ctaagt", "gcta", "ttca", "atgcatc" };
  vector<string> input2{ "ekpijtseahvmprvefkgn", "yyevvcmeekpijtseahvm",
                         "vsfcyyevvcmeekp",      "xwmkoqhxvrovlmmvsfcy",
                         "cmeekpijtseahvmpr",    "oqhxvrovlmmvsfcyy",
                         "zpuemtclxbxwsypfxevx", "clxbxwsypfxevxw",
                         "fkgnjgdvfygnlckyiju",  "xevxwmkoqhxvrovlmm" };
  cout << "start:\n";
  Solution sol2;
  cout << sol2.shortestSuperstring(input2) << endl;
  return 0;
}