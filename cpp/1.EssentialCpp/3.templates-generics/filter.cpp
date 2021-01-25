#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
/* function adapters
 * stl privide pre-defined function objects:
 * - relation: plus<>, minus<>, negate<>, multiplies<>, divides<>, modules<>
 * - arithmatics: less<>, greater<>, less_equal<>, greater_equal<>, equal_to<>,
 *   not_equal_to<>
 * - logical: logical_and<>, logical_or<>,logical_not<>
 *
 * `std::sort`: could take a function object as the comparator
 *    std::sort(c.begin(), c.end(), greator<decltype(c)::value_type>());
 * */

vector<int>
filter(const vector<int>& vec, int filter_value, bool (*pred)(int, int));

bool
less_than(int a, int b)
{
  return a < b;
}
bool
greater_than(int a, int b)
{
  return a > b;
};

vector<int>
filter(const vector<int>& vec, int filter_value, bool (*pred)(int, int))
{
  vector<int> nvec;
  for (int i = 0; i < vec.size(); ++i)
    if (pred(vec[i], filter_value))
      nvec.push_back(vec[i]);
  return nvec;
}

vector<int>
filter(const vector<int>& vec, int val, less<int>& lt)
{
  vector<int> nvec;
  vector<int>::const_iterator iter = vec.cbegin();

  while ((iter = find_if(iter, vec.cend(), bind2nd(lt, val))) != vec.cend()) {
    nvec.push_back(*iter);
    ++iter;
  }
  return nvec;
}

int
count_occurs(const vector<int>& vec, int val)
{
  vector<int>::const_iterator iter = vec.cbegin();
  int occurs = 0;
  while ((iter = find(iter, vec.cend(), val)) != vec.cend()) {
    ++occurs;
    ++iter;
  }
  return occurs;
}

template<typename InputIterator,
         typename OutputIterator,
         typename ElemType,
         typename Comp>
OutputIterator
filter(InputIterator first,
       InputIterator last,
       OutputIterator at,
       const ElemType& val,
       Comp lt)
{
  while ((first = find_if(first, last, bind2nd(lt, val))) != last) {
    cout << "found value: " << *first << endl;
    *at = *first;
    ++at;
    ++first;
  }
  return at;
}

int
main()
{
  const int elem_size = 8;
  int ia[elem_size] = { 12, 8, 43, 0, 6, 21, 3, 7 };
  vector<int> ivec(ia, ia + elem_size);
  int ia2[elem_size];
  vector<int> ivec2(elem_size);

  cout << "filtering array[] less than 8" << endl;
  filter(ia, ia + elem_size, ia2, elem_size, less<int>());
  cout << "filtering vector greater than 8" << endl;
  filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, greater<int>());
  cout << "filtering vector no less than 8" << endl;
  filter(ivec.begin(), ivec.end(), ivec2.begin(), elem_size, not2(less<int>()));
  return 0;
}
