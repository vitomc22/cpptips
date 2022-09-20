#include "prototipoclasse.hpp"
#include <iostream>

typedef std::string String;
Exemplo::Exemplo() {
  std::cout << "Iniciando o nosso exemplo construtor" << '\n';
}
Exemplo::Exemplo(int x, int *y) {
  std::cout << "A soma de " << x << " mais " << *y << " eh igua a " << x + (*y)
            << '\n';
}
Exemplo::~Exemplo() { std::cout << "Fechando o projeto" << '\n'; }
void Exemplo::listaArray(String array[]) {
  std::cout << "Ainda sendo  implementada" << '\n';
}
String Exemplo::mostra(String novaSenha) {
  senha = novaSenha;
  return senha;
}
