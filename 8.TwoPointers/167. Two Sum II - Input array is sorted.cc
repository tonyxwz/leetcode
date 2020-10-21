class Solution
{
public:
  vector<int> twoSum(vector<int>& numbers, int target)
  {
    const int n = numbers.size();
    int l = 0;
    int r = n - 1;
    while (l < r) {
      const int x = numbers[l] + numbers[r];
      if (x == target) {
        return { l + 1, r + 1 };
      } else if (x < target) {
        l++;
      } else {
        r--;
      }
    }
    return {};
  }
};
