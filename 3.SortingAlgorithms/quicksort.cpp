#include <algorithm>
#include <functional>
#include <iostream>
#include <iterator>
#include <vector>
#include <cstdlib>

using std::function;

namespace sort {

template <class Itr>
Itr median(Itr a, Itr b, Itr c) {
  if (*a < *b)
    if (*b < *c)
      return b;
    else if (*a < *c)
      return c;
    else
      return a;
  else if (*a < *c)
    return a;
  else if (*c < *b)
    return b;
  else
    return c;
}

template <class Itr>
Itr partition(Itr begin, Itr end) {
  // choose pivot
  // Itr ipivot = median(begin, begin + (end - begin) / 2, end - 1);
  // 快速排序理论上只需要用小于号进行比较就可以实现
  // 左边的组全部<=pivot, 右边全部>=pivot, 在接下来的排序中，左边等于pivot的元素会全部移到最右边
  // 右边等于pivot的元素会全部移到最左边，实际上数组仍然是排列好的，但这种排序不能保证稳定，即
  // 原本相等的元素保持其未排序前的相对顺序.
  Itr ipivot = end - 1;
  typename std::iterator_traits<Itr>::value_type pivot = *ipivot;
  Itr l = begin, r = end - 1;
  while (1) {
    while (*l < pivot) ++l;
    while (pivot < *r) --r;
    if(l >= r) return l;
    else{
      std::iter_swap(l, r);
      l++;
      r--;
    }
  }
  return l;
}

template <class Itr>
void quickSort(Itr begin, Itr end) {
  // std::vector<int>& v) {
  // some guard
  if (end <= begin + 1) return;
  Itr mid = partition(begin, end);
  // std::copy(begin, end, std::ostream_iterator<int>(std::cout, " "));
  // std::cout << "\t" << (mid - begin);
  // std::cout << std::endl;
  quickSort(begin, mid);
  quickSort(mid, end);
}

}  // namespace sort

void test_quicksort(int length) {
  std::vector<int> v(length);
  for(auto& i:v) {
    i = std::rand() % length;
  }
  std::cout << length;
  sort::quickSort(v.begin(), v.end());
  std::cout << (std::is_sorted(v.begin(), v.end()) ? "success" : "fail") << std::endl;
}

int main() {
  std::vector<int> nums{70, 100, 200, 2000, 30000, 2};
  for(auto i:nums)
    test_quicksort(i);
  function<void(int, int)> huahua = [&](int l, int r) {
    if (l >= r) return;
    int i = l;
    int j = r;
    int p = nums[l + rand() % (r - l + 1)];
    while (i <= j) {
      while (nums[i] < p) ++i;
      while (nums[j] > p) --j;
      if (i <= j) std::swap(nums[i++], nums[j--]);
    }
    huahua(l, j);
    huahua(i, r);
  };
  // huahua(0, nums.size() - 1);
  // std::copy(nums.begin(), nums.end(), std::ostream_iterator<int>(std::cout, "
  // "));
  // sort::quickSort(nums.begin(), nums.end(), nums);
  return 0;
}