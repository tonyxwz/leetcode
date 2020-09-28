#include <iostream>
#include <vector>
using namespace std;

template <typename It>
void swap(It a, It b)
{
  auto tmp = *a;
  *a = *b;
  *b = tmp;
}

template <typename It>
It partition(It begin, It end)
{
  auto pivot = *(end - 1);
  int offset = 0;
  for (It i = begin; i != (end - 1); ++i)
  {
    if (*i <= pivot)
    {
      swap(i, begin + offset);
      ++offset;
    }
  }
  swap(begin + offset, end - 1);
  return begin + offset;
}

template <typename It>
void quickSort(It begin, It end)
{
  if (end - begin <= 0)
    return;
  auto q = partition(begin, end);
  quickSort(begin, q);
  quickSort(q+1, end);
}

class Solution
{
public:
  vector<int> sortArray(vector<int> &nums)
  {
    quickSort(nums.begin(), nums.end());
    return nums;
  }
};

int main()
{
  vector<int> v{5, 3, 4, 8};
  for (const auto &i : v)
    cout << i << " ";
  Solution s;
  auto v2 = s.sortArray(v);
  for (const auto &i : v2)
    cout << i << " ";
  return 0;
}