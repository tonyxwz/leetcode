#include <iostream>
using namespace std;

class BaseSeq
{
public:
  int elem(int pos);
  virtual void gen_elems(int pos) = 0;
  const char* what_am_i() const;
  ostream& print(ostream& os = cout) const;
  bool check_integrity(int pos);
  static int max_elens();
};
