class Solution
{
public:
  int numRescueBoats(vector<int>& people, int limit)
  {
    int ans = 0;
    sort(people.begin(), people.end());
    int l = 0, r = people.size() - 1;
    while (l < r) {
      if (people[l] + people[r] > limit) {
        ++ans;
        --r;
      } else {
        ++ans;
        --r;
        ++l;
      }
    }
    if (l == r)
      ++ans;
    return ans;
  }
};
