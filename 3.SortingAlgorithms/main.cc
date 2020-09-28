// #ifdef _MSC_VER
// #pragma warning(disable : 4530)
// #endif
#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <chrono>
#include <iomanip>
#include <string>
#include <cstdlib>

#include "sorting.hpp"

template<class T, class F>
std::vector<T> runFunc(std::vector<T> vec, F f, const std::string& algoName) {
  bool a = std::is_sorted(vec.begin(), vec.end());
  std::cout << std::setw(20) << std::left << algoName << ": ";
  auto t0 = std::chrono::high_resolution_clock::now();
  f(vec.begin(), vec.end());
  auto t1 = std::chrono::high_resolution_clock::now();
  std::chrono::duration<double> elapsed = t1 - t0;
  std::cout << "Elapsed time: " << elapsed.count() << "s. ";
  // for(auto i:vec) std::cout << i << " ";
  std::cout << std::setw(7) << std::right << 
    (!a && std::is_sorted(vec.begin(), vec.end()) ? "success" : "fail") << std::endl;
  return vec;
}

int main() {
  std::cout << "Comparing sorting algorithms" << std::endl;
  int num = 0;
  std::cout << "num: ";
  std::cin >> num;
  auto v = new std::vector<int>(num);
  // std::mt19937 g(100);
  for(int i = 0; i < num; ++i)
    v->at(i) = std::rand() % num;
  // std::shuffle(v->begin(), v->end(), g);

  runFunc(*v, st::bubbleSort<std::vector<int>::iterator>, "Bubble sort");
  runFunc(*v, st::insertionSort<std::vector<int>::iterator>, "Insertion sort");
  runFunc(*v, st::selectionSort<std::vector<int>::iterator>, "Selection sort");
  runFunc(*v, st::shellSort<std::vector<int>::iterator>, "Shell sort");
  runFunc(*v, st::quickSort<std::vector<int>::iterator>, "Quick sort");
  runFunc(*v, st::mergeSort<std::vector<int>::iterator>, "Merge sort");

  delete v;
  return 0;
}
