#include <algorithm>
#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

/* the implementation in filter.cpp poses a restriction on the outiterator that
 * the capacity must be enough (the same as the input iterator's at the worst
 * case scenario).
 *
 * The problem is that, for non-worstcast scenarios, the size of the OutIterator
 * is too big.
 *
 * however, passing an empty container is not possible because our
 * implementation of `filter` requires the data is copied to an existing place.
 *
 * Solution: insertion adaptors
 * std::back_inserter, std::inserter, std::front_inserter in header file
 * <iterator>
 *
 * */

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

int main() {
  const int elem_size = 8;
  int ia [ elem_size ] = {12, 3, 4, 67, 7, 14, 2, 6};
  vector<int> ivec(ia, ia+elem_size);
  int ia2[ elem_size ];
  vector<int> ivec2;
  cout << "using primitive array as output iterator" << endl;
  filter(ia, ia+elem_size, ia2, elem_size, greater<int>());


  // Note that here `ivec2` is doen't have space allocated before passing into
  // the filter function, instead, back_insert replaces operator= with push_back
  // method of the container. This is not hard to image, the back_inserter
  // returns a object who's operator= uses the push_back method the underlying
  // container.
  // *Attention!* incrementing the back_insert_iterator is an `no-op`, simply
  // returns this *this (iterator object itself)

  cout << "using vector and insertion adaptor as output iterator" << endl;
  filter(ivec.cbegin(), ivec.cend(), back_inserter(ivec2), elem_size, greater<int>());
  return 0;
}

