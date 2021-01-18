#include <fstream>
#include <iostream>
#include <vector>

/* Optional parameter could only be defined once, either in function definition
or in function declaration, but not in both places. Traditionally, optional
paramters are defined in header files function declaration, so that they are
visible to users.

If an optional parameter is allow to be empty (null), it has to be defined as a
pointer, not a reference.
 */
using namespace std;

void
bubbleSort(vector<int>& array, ostream* ofil = 0);
void
display(const vector<int>& array, ostream& os = cout);

int
main()
{
  vector<int> a{ 1, 5, 2, 6, 10, 7, 1, 9 };
  bubbleSort(a, &cout);
  display(a);
  return 0;
}

void
bubbleSort(vector<int>& array, ostream* ofil)
{
  for (int i = 0; i < array.size(); ++i) {
    for (int j = i + 1; j < array.size(); ++j) {
      if (array[i] > array[j]) {
        if (ofil != 0) {
          (*ofil) << "about to call swap! "
                  << "a: " << array[i] << ", b: " << array[j] << endl;
        }
        swap(array[i], array[j]);
      }
    }
  }
}

void
display(const vector<int>& array, ostream& os)
{
  for (int i = 0; i < array.size(); ++i)
    os << array[i] << " ";
  os << endl;
}