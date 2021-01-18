#include "ch2.hpp"
#include <ios>

int main() {
  int pos;
  ElemType elem;
  bool more = true;
  char yn;

  while (more) {
    // while (cout << "Enter position in the sequence: " && ! (cin >> pos)) {
    //   cin.clear();
    //   string line;
    //   getline(cin, line);
    //   cout << "bad number " << line << "!" << endl;;
    // }
    
    cout << "Enter position in the sequence: ";
    cin >> pos;
    if (cin.fail()) {
      cin.clear();
      cin.ignore();
      cout << "bad number!" << endl;
      continue;
    }
    
    if (fibon_elem(pos, elem)) {
      cout << "Ans: " <<  elem << endl;
    }
    cout << "Another round? (y/n) ";
    cin >> yn;
    more = yn == 'y' ? true : false;
  }
  return 0;
}