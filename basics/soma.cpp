#include <iostream>

int soma(int a, int b) { return a + b; }

void mostra(int result) { std::cout << result; }

int main(int argc, char const *argv[]) {
  int resultado = soma(10, 20);

  mostra(resultado);
  return 0;
}
