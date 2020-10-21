class Solution
{
public:
  vector<int> sortedSquares(vector<int>& A)
  {
    const int n = A.size();
    vector<int> ans;
    int j = 0;
    while (j < n && A[j] < 0)
      j++;
    int i = j - 1;
    while (i >= 0 && j < n) {
      if (A[i] * A[i] < A[j] * A[j]) {
        ans.push_back(A[i] * A[i]);
        i--;
      } else {
        ans.push_back(A[j] * A[j]);
        j++;
      }
    }
    while (i >= 0) {
      ans.push_back(A[i] * A[i]);
      i--;
    }
    while (j < n) {
      ans.push_back(A[j] * A[j]);
      j++;
    }
    return ans;
  }
};
