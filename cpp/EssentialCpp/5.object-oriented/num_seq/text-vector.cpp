#include <vector>
#include <iostream>
#include <string>


int main(int argc, char* argv[]) {
  using namespace std;
  vector<string> v;
  v.push_back("this is a test string");

  for (int i = 0; i < argc; ++i)
    v.push_back(argv[i]);

  string bk;
  string& rbk = bk;
  rbk = v.back();
  string& rbk2 = v.back();
  v.pop_back();
  string& bk2 = v[0];
  cout << bk << " " << rbk << " " << rbk2 << " " << bk2 << endl;
  return 0;
}
