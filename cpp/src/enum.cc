#include <iostream>
#include <cstdint>
// // https://en.cppreference.com/w/cpp/language/enum

enum smallenum: std::int16_t {
  a=9, b, c
};


// unscoped enum
enum color {
  red,
  yellow,
  green,
  blue,
};

enum class continent: char {
  asia = 'A',
  oceania = 'O'
};


// no name, question conflict?
// nope: compiler error
// enum {
//   a, b, c
// };


std::ostream& operator<<(std::ostream& os, color c) {
  switch(c){
    case red: os << "red"; break;
    case yellow: os << "yellow"; break;
    case green: os << "green"; break;
    case blue: os << "blue"; break;
    default: os.setstate(std::ios_base::failbit);
  }
  return os;
}

std::ostream& operator<<(std::ostream& os, continent c) {
  return os << static_cast<char>(c);
}

int main() {
  color c = red;
  continent home = continent::asia;
  std::cout << "color = " << c << "\n"
       << "home = " << home  << "\n"
       << "a = " << a << std::endl;
  return 0;
}