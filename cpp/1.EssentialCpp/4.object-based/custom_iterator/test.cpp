#include "Vec.hpp"
#include <iostream>

void helper(const ess::Vec &v) {
  for (int i = 0; i < v.size(); i++)
    std::cout << v[i] << std::endl;
}

int main() {
  using namespace std;
  /* "C++'s most vexing parse"
   * no parenthesis when calling default constructor with no arguments,
   * otherwise it is parsed as a function definition.
   *
   * C++ 11 introduced brace initialization (uniform initialization)
   * all initializations can be called using this in a not ambiguous way.
   * */

  ess::Vec vec0{};
  ess::Vec vec{12, 100};
  ess::Vec vec2{vec};
  ess::Vec vec3 = vec2;
  vec2[0] = 200;
  vec3[0] = 300;

  helper(vec);
  helper(vec2);
  helper(vec3);

  cout << "test iterator" << endl;
  int start = 1000;
  for (auto &i : vec3)
    i = (start += 100);
  for (const auto &i : vec3) {
    cout << i << endl;
  }
  return 0;
}
