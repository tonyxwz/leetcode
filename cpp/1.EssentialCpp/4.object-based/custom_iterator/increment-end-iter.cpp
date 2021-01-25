#include <iostream>
#include <vector>


int main()  {
  using namespace std;
  std::vector<int> vec{1, 2, 3, 4, 5, 6};
  auto e = vec.end();

  std::vector<int> vec2{1, 2, 3, 4, 5, 6};
  cout << e.base() << endl;
  return 0;
}

