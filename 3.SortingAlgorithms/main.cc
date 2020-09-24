// #ifdef _MSC_VER
// #pragma warning(disable : 4530)
// #endif
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include "sorting.hpp"

template<class T, class F>
std::vector<T> runFunc(std::vector<T> vec, F f) {
  auto t0 = std::chrono::high_resolution_clock::now();
  f(vec.begin(), vec.end());
  auto t1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = t1 - t0;
  std::cout << "Elapsed time: " << elapsed.count() << "s. ";
  return vec;
}

int main() {
  std::cout << "Comparing sorting algorithms" << std::endl;
  int num = 0;
  std::cout << "num: ";
  std::cin >> num;
  auto v = new std::vector<int>(num);
  std::mt19937 g(100);
  for(int i = 0; i < num; ++i)
    v->at(i) = i + 1;
  std::shuffle(v->begin(), v->end(), g);

  std::cout << "Bubble sort: ";
  auto r1 = runFunc(*v, st::bubbleSort<std::vector<int>::iterator>);
  std::cout << (std::is_sorted(r1.begin(), r1.end()) ? "success" : "fail") << std::endl;
  
  std::cout << "Insertion sort: ";
  auto r2 = runFunc(*v, st::insertionSort<std::vector<int>::iterator>);
  std::cout << (std::is_sorted(r2.begin(), r2.end()) ? "success" : "fail") << std::endl;

  std::cout << "Quick sort: ";
  auto r3 = runFunc(*v, st::quickSort<std::vector<int>::iterator>);
  std::cout << (std::is_sorted(r3.begin(), r3.end()) ? "success" : "fail") << std::endl;

  // for (auto i : r3)
  //   std::cout << i << " ";

  std::cout << "Shell sort: ";
  auto r4 = runFunc(*v, st::shellSort<std::vector<int>::iterator>);
  std::cout << (std::is_sorted(r4.begin(), r4.end()) ? "success" : "fail") << std::endl;

  delete v;
  return 0;
}
