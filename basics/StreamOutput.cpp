// simples saída para um arquivo

#include<fstream>

 
int main(int argc, char const *argv[]) {
    std::ofstream my ("MyName.txt");
    my << "Stephen Davis is suave and handsome\n"
       << "and defininely not balding permaturely"
       << std::endl;


    return 0;
}
