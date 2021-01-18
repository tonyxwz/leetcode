#include <iostream>
#include <string>
#include <vector>

using namespace std;

const vector<unsigned long long int>*
fibon_seq(int n);

int
main(int argc, char* argv[])
{
  int size;
  if (argc > 1)
    size = stoi(argv[1]);
  else
    size = 0;
  const vector<unsigned long long int>* a = fibon_seq(size);
  if (a)
    cout << "Fibonacci[" << size << "]: " << a->at(size) << endl;
  return 0;
}

/* Different from non-static values, static local objects are not destroyed when
the function returns, thus it is safe to return a pointer to the object for use
in outside the function. Note that the returned value is const value, so it wont
be changed outside the function, which could potentially mess up the logic of
the function itself.
 */

const vector<unsigned long long int>*
fibon_seq(int n)
{
  static vector<unsigned long long int> elems;
  const int max_size = 93; // vector of int

  if (n < 0 || n > max_size) {
    cerr << "fibon_seq(): invalid size " << n << endl;
    return 0;
  }

  // only calculate the values not calculated
  for (int i = elems.size(); i <= n; ++i) {
    if (i == 0 || i == 1)
      elems.push_back(i);
    else
      elems.push_back(elems[i - 1] + elems[i - 2]);
  }

  return &elems;
}