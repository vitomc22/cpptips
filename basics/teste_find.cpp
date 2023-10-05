// teste find
#include <iostream>

int main(int argc, char const *argv[]) {
  std::string teste = " aqui tem treta";

  //find retorna a posição da string que ele entra
  //por isos pra usar em um teste de contain, precisamos o npos
  //ou seja caso nao retorne posicção, ele não achou.
  (teste.find("treta") != std::string::npos)
      ? std::cout << "tem treta aqui vei!" << '\n'
      : std::cout << " nao tem treta vei :( ... " << '\n';

  return 0;
}
