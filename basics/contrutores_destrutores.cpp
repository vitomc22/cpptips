#include <iostream>
class Qualquer
{
public:
    Qualquer(){
        std::cout << "Eu sou qualquer" << '\n';
    };
     Qualquer(int x, int y){
        std::cout << "x * y é igual a: " << x*y << '\n';
    };

    void funcao_membro_qualquer(){
        std::cout << "Eu sou uma função membro qualquer!" << '\n';
    }

      void outra_funcao_membro_qualquer(){
        std::cout << "Eu sou outra função membro qualquer!" << '\n';
    }


    ~Qualquer(){
        std::cout << "Saindo do escopo com destrutor!";
    };
};

int main(int argc, const char** argv) {
Qualquer q(5,10);
q.funcao_membro_qualquer();
q.outra_funcao_membro_qualquer();
Qualquer q2;



    return 0;
}