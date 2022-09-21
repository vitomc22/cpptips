#include <iostream>

int main() {

  int8_t a = 200;
  uint8_t b = 100;

  if (a > b) {
    std::cout << "A Greater" << '\n';
  } else {
    std::cout << "Less" << '\n';
    ;
  }

  std::cout << "size A: " << sizeof(&a) << '\n';
  std::cout << "size B: " << sizeof(&b) << '\n';

  return 0;
}