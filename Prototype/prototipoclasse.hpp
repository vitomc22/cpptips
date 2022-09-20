#ifndef PROTOTIPODECLASSE_HPP
#define PROTOTIPODECLASSE_HPP
#include <iostream>
class Exemplo {
public:
  typedef std::string String;
  Exemplo();
  Exemplo(int, int *);
  ~Exemplo();
  void listaArray(String array[]);
  String mostra(String novaSenha);

private:
  static constexpr double piquadrado = 3.14 * 2;

protected:
  String senha = {"Minha senha secreta"};
};

#endif