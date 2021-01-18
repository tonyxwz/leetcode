#include <iostream>
#include <string>
#include <vector>

using namespace std;
using fibtype = unsigned long long int;

/* it makes the program easier to understand if the code is divided into smaller
components such as functions. However, this means that the program will have to
make more function calls, which could affect the execution efficiency. Instead
of preparing two different versions of the same function, one divided for
clarity, one integrated for efficiency, you could simply write the functions as
inline functions and the compiler will automatically substitute the function
into an efficient one. */

const vector<fibtype>*
fibon_seq(int size);


bool
size_ok(int size)
{
  const int max_size = 93;
  if (size < 0 || size > max_size) {
    cerr << "fibon_seq(): invalid size " << size << endl;
    return false;
  }
  return true;
}

const vector<fibtype>* fibon_seq(int size)
{
  static vector<fibtype> elems;
  if (!size_ok(size))
    return 0;

  for (int i = elems.size(); i <= size; ++i) {
    if (i == 0 || i == 1)
      elems.push_back(i);
    else
      elems.push_back(elems[i - 1] + elems[i - 2]);
  }

  return &elems;
}

/* inline also automatically expand the function that is called by it
However, inline is just a suggestion to the compiler and depends on the compiler
implementation. In general, functions that are small and short are most suitable
for inline substitution.

inline functions are defined in header files.
*/

inline bool fibon_elem(int n, fibtype &target) {
  auto elems = fibon_seq(n);
  if (elems) {
    target = elems->at(n);
    return true;
  } else {
    return false;
  }
}

int
main(int argc, char* argv[])
{
  int size;
  if (argc > 1)
    size = stoi(argv[1]);
  else
    size = 0;
  fibtype result = 0;
  if (fibon_elem(size, result)) {
    cout << "Fibonacci[" << size << "]: " << result << endl;
    return 0;
  } else {
    cout << "Error" << endl;
    return -1;
  }
}