#pragma once
#include <cstdlib>

namespace st {
// sort from begin to end-1
template <class It>
void mySort(It begin, It end) {}

// helper func
template <class It>
void mySwap(It a, It b) {
  // std::iterator_traits<It>::value_type tmp = *j;
  auto tmp = *a;
  *a = *b;
  *b = tmp;
}
template <class T>
const T &median(T &a, T &b, T &c) {
  if (a < b)
    if (b < c)
      return b;
    else if (a < c)
      return a;
    else
      return c;
  else if (a < c)
    return a;
  else if (c < b)
    return b;
  else
    return c;
}
/*****************************************************************************
                            dumb algorithms
*****************************************************************************/

// bubble sort, the easiest sorting algorithm
// time: O(n^2)
template <class It>
void bubbleSort(It begin, It end) {
  for (It i = end - 1; i != begin; i--)
    for (It j = begin; j != i; j++)
      if (*j > *(j + 1)) mySwap(j, j + 1);
}

// insertion sort (inplace)
template <class It>
void insertionSort(It begin, It end) {
  if (begin == end) return;
  // initially begin is a sorted array
  for (It i = begin + 1; i != end; i++)
    // move left if left neighbour is smaller
    for (It j = i; j != begin && *(j - 1) > *j; j--) mySwap(j - 1, j);
}

template <class It>
void shellSort(It begin, It end) {
  // 逐渐减小间隔
  auto size = end - begin;
  for (int inc = size / 2; inc > 0; inc /= 2) {
    for (It i = begin + inc; i < end; ++i) {
      auto tmp = *i;
      It j;
      for (j = i; begin <= j - inc; j -= inc) {
        if (tmp < *(j - inc))
          *j = *(j - inc);
        else
          break;
      }
      *j = tmp;
    }
  }
}

// for the easy of development, use integer offsets rather than iterators
template <class It>
void shellSort2(It begin, It end) {
  auto N = end - begin;
  for (int inc = N / 2; inc > 0; inc /= 2) {
    for (int i = inc; i < N; ++i) {
      auto tmp = *(begin + i);
      int j = i;
      for (; j >= inc; j -= inc) {
        if (tmp < *(begin + j - inc))
          *(begin + j) = *(begin + j - inc);
        else
          break;
      }
      *(begin + j) = tmp;
    }
  }
}

template <class It>
void selectionSort(It begin, It end) {
  for (It i = begin; i != end; ++i) {
    auto minI = i;
    for (It j = i+1; j != end; ++j) {
      if(*j < *minI)
        minI = j;
    }
    mySwap(i, minI);
  }
}

/*************************************************************************************
 */
// Divide and conquer
template <class It>
It partition(It begin, It end) {
  // pivot: element to be placed at the right position
  // select pivot to be the value on the right hand side
  //随机选一个值作为pivot并将它移到队尾
  auto ipivot = begin + std::rand() % (end - begin);
  auto pivot = *ipivot;
  mySwap(ipivot, end - 1);
  // auto pivot = *(end - 1);
  int num_left = 0;
  for (It i = begin; i != end - 1; i++) {
    // swap if current value should be on the left side of pivot
    if (*i <= pivot) {
      mySwap(begin + num_left, i);
      num_left++;
    }
  }
  mySwap(begin + num_left, end - 1);
  return (begin + num_left);
}

// https://stackoverflow.com/a/5001474/5575055
// quicksort using random pivot selection can overcome the unsorted arrays
// with a pattern.
template <class It>
It betterPartition(It begin, It end) {
  auto pivot = *(begin + std::rand() % (end - begin));
  while (begin < end) {
    while (*begin < pivot) ++begin;
    // --last here have two meaning, 1. solve offedge end problem, 2. move to
    // next element
    --end;
    while (pivot < *end) --end;
    mySwap(begin, end);
    ++begin;
  }
  return begin;
}

template <class It>
void quickSort(It begin, It end) {
  auto size = end - begin;
  if (size <= 0) return;

  auto p = partition(begin, end);
  quickSort(begin, p);
  quickSort(p + 1, end);
}

template <class It>
void heapSort(It begin, It end) {}

template <class It>
void mergeSort(It begin, It end) {
  if (begin+1 == end) return;
  // divide into two parts
  It mid = begin + (end - begin) / 2;
  mergeSort(begin, mid);
  mergeSort(mid, end);
  // by this time begin-mid and mid-end should be separately sorted
  It l = begin, r = mid;
  while(l != mid && r != end) {
    if (*l < *r) ++l;
    else {
      // shift left by one
      auto value = *r;
      auto index = r;
      while(index != l) {
        *index = *(index - 1);
        index--;
      }
      *l = value;
      l++;
      r++;
      mid++;
    }
  }
}

// use stl::set
template <class It>
void bstSort(It begin, It end) {}

// huahua
template <class It>
void countingSort(It begin, It end) {}
}  // namespace st
