#include <iostream>
#include <fstream>

using namespace std;

int main() {
  ifstream infile("test.txt");
  int elem_cnt;
  infile >> elem_cnt;
  cout << elem_cnt << endl;
  return 0;
}
