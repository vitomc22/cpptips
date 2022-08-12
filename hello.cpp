#include <iostream>
#include <stdlib.h>
#include <vector>

int num{10};
int num2{20};
int num3{50};

int main(int argc, char const *argv[]) {
  std::vector<int> numeros{num, num2, num3};

  for (const auto &i : numeros) {
       std::cout << i << '\n';
  }

   auto mult = []() { return num+num2+num3;};

   std::cout << mult() << '\n';

  return 0;
}
