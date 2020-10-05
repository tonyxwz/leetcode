#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
#include <string>

using namespace std;

int main() {
  map<int, int> m;
  unordered_map<string, int> um;
  vector<int> v;

  v.push_back(78);
  um["you"] = 78;
  m[8] = 78;

  cout << sizeof(v[0]) << " " << sizeof(um["you"]) << " " << sizeof(m[8]) << endl;
  return 0;
}