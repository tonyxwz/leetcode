#include <algorithm>
#include <iostream>

int main() {
  using namespace std;
  char str[] = "mississippi";
  char substr[] = "ss";
  char* piter = search(str, str+12, substr, substr+2);
  // search for first s repeated twice
  char* piter2 = search_n(str, str+12, 3, 's');
  cout << piter - str << endl;
  cout << piter2 - str << endl;
  return 0;
}

