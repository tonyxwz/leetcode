#include <unordered_map>
#include <vector>
using namespace std;

class Solution
{
  // sliding window
  //
private:
  // the number of subarrays with at most k distinct elements
  int subarray(vector<int>& A, int k)
  {
    int ans = 0;
    // The nice condition provided in the problem:
    /* 1 <= A.length <= 20000 */
    /* 1 <= A[i] <= A.length */
    /* 1 <= K <= A.length */
    /* unordered_map<int, int> count; */
    vector<int> count(A.size() + 1);

    int l = 0;
    for (int r = 0; r < A.size(); r++) {
      // build a range [l, r] containing exactly k distinct elements
      if (count[A[r]] == 0)
        k--; // number of elements to add into [l, r]
      count[A[r]]++;

      // move left pointer to the first position where the range contains less
      // than k elements
      while (k < 0) {
        count[A[l]]--;
        if (count[A[l]] == 0) {
          k++;
        }
        l++;
      }
      // k < 0: the range contains more than k distinct elements
      // k == 0: the range contains exactly k distinct elements
      // so all the indices from the position of l when k == 0 to r are all
      // valid
      ans += r - l + 1;
    }
    return ans;
  }

public:
  int subarraysWithKDistinct(vector<int>& A, int K)
  {
    return subarray(A, K) - subarray(A, K - 1);
  }
};
