#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int
main()
{
  using namespace std;
  vector<int> vec{ 1, 2, 3, 4, 5, 6, 7 };
  vector<int> vec2{ vec };

  transform(vec.cbegin(), vec.cend(), vec2.cbegin(), vec2.begin(), plus<int>());
  for (const auto& i : vec2)
    cout << i << " ";
  cout << endl;
  return 0;
}
