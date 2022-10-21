#include <iostream>
#include <vector>
//vector é um container de array, na prática é um array com super poderes, como iteradores begin e end
//são dinamicos e  por isso não é necessário declarar o tamanho por exemplo

int main(int argc, char const *argv[]) {
  std::vector<int> numeros;

  for (int i = 0; i < 5; i++) {
    numeros.push_back(i);
  }

  for (auto i = numeros.begin(); i != numeros.end(); ++i) {
    std::cout << "numeros de i: " << *i << '\n';
  }

  std::cout << "Tamanho do vector numeros: " << numeros.size() << '\n';
  std::cout << "Tamanho máximo do vector numeros: " << numeros.max_size() << '\n';
  std::cout << "Capacidade do vector numeros: " << numeros.capacity() << '\n';

  std::cout << "Valor da primeira posição " << numeros.front() << '\n';
  std::cout << "Valor da ultima posição " << numeros.back() << '\n';
  std::cout << "Valor da posição 3 " << numeros.at(3) << '\n';
  std::cout << "Ajustando Valor da posição 3 para 15 " << '\n';
  numeros.insert(numeros.begin()+2,15);
  std::cout << "valor da posicao 3 ajustado para: " << numeros.at(2) << '\n';


  std::cout << "Limpando vector numeros... "<< '\n';
  numeros.clear();

  std::cout << "Tamanho depois de limpar o vector:  "<< numeros.size() << '\n';

  

  return 0;
}
