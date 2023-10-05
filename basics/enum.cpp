#include <iostream>

enum class Cores{
    color_blue, color_purple
};

enum class Frutas{
    laranja,pessego
};


int main(int argc, char const *argv[]){
    
   Cores cores;
   Frutas frutas;

    //cores == frutas ? std::cout << "São iguais" : std::cout << "Não são iguais";
    std::cout << " o numero de cores é : " << static_cast<int>(cores) << '\n';
    return 0;
}
