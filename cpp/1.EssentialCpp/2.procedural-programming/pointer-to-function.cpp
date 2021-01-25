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

const vector<fibtype>*
fibon_seq(int size)
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

/* pointer to function offers more flexibility of the function
The form of pointer to a function is very complicated:
  - it first have to specify the return value
  - then the argument list
  - * symbol meaning it is a pointer to somewhere
*/

bool
seq_elem(int n,
         fibtype& target,
         const vector<fibtype>* (*seq_func_ptr)(int) = 0)
{
  if (!seq_func_ptr)
    return false;
  auto elems = seq_func_ptr(n);
  if (elems) {
    target = elems->at(n);
    return true;
  } else {
    return false;
  }
}

enum seq_func
{
  ns_fib,
  ns_lucas,
  ns_pell,
  ns_triang,
  ns_square,
  ns_pent
};

const vector<fibtype>* (*seq_funcs[])(int) = { fibon_seq };

int
main(int argc, char* argv[])
{
  int size;
  if (argc > 1)
    size = stoi(argv[1]);
  else
    size = 0;
  fibtype result = 0;
  if (seq_elem(size, result, seq_funcs[ns_fib])) {
    cout << "Fibonacci[" << size << "]: " << result << endl;
    return 0;
  } else {
    cout << "Error" << endl;
    return -1;
  }
}