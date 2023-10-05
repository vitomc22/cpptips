#include <iostream>
#include <regex>
#include <string>
//quero fazer isso -> 11-1A1-254
bool incia_com_letra(std::string str){
    std::regex re ("^[a-zA-Z]"); //verifica se tem as letras de a até z
    std::smatch match;
    return std::regex_search(str,match,re);
} 

int main(int argc, char const *argv[]){
    std::string str = "1Teste";
    incia_com_letra(str) ? std::cout <<" Sim, inicia com letra" << '\n' : std::cout << "Não inica com letra" << '\n';

    return 0;
}

//g++

