#include <iostream>
#include <string>

/*
 * You dumbass, [] operator of course returns the value stored in the array.
 */
int main() {
  using namespace std;

  string words[] = {"1234", "wqewrq", "asfagfw", "ztafw", "hewrtwe"};
  int nums[] = {1, 2, 3, 4, 5};
  cout << nums << " vs " << nums[0] << endl;
  cout << words << " " << words+2 << endl;
  for (int i = 0; i < 5; ++i)
    cout << words+i << ": " << *(words+i) << endl;
  return 0;
}
