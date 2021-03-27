#include "leetcode.h"

class NumArray
{
private:
  vector<int> dp_;
  const vector<int>& nums_;
  int ub_; // upper bound of accumulated items in nums_

  void acc(int til)
  {
    cout << "acc " << ub_ << " " << til << endl;
    for (int i = max(1, ub_); i <= til + 1; ++i) {
      dp_[i] = dp_[i - 1] + nums_[i - 1];
    }
    ub_ = til;
  }

public:
  NumArray(vector<int>& nums)
    : dp_{ vector<int>(nums.size() + 1, 0) }
    , nums_{ nums }
    , ub_{ -1 }
  {}

  int sumRange(int left, int right)
  {
    if (ub_ < right)
      acc(right);
    // dp[right+1] - dp[left+1]

    return dp_[right + 1] - dp_[left];
  }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */