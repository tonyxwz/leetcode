#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

int main() {
  vector<string> v = {"45.8", "34", "5"};
  ostringstream oss;
  for (auto it = v.begin(); it != v.end(); it++) {
    oss << *it << " ";
  }

  // cout << oss.str() << endl;

  istringstream iss(oss.str());

  string s;
  // operator>> of input stream stop at (and skips) white spaces
  iss >> noskipws;
  while (iss >> s)
    cout << s << " ";
  cout << endl;

  char c;
  iss.clear();
  iss.seekg(0, iss.beg);
  while (iss >> c)
    cout << c << " ";
  cout << endl;

  return 0;
}
