#include <iostream>
#include <ostream>

using std::string;
using std::cout;
using std::endl;

int main(int argc, char const *argv[]){
    
    string str1  = "Minha corda legal";
    string str2 = "Minha corda beleza";
    int resultado = str1.compare(str2);

    cout << (str1 == str2 ? "Método que conhecemos: SIM, são iguais" : "Método que conhecemos: NAO") << endl;

    cout << (resultado == 0 ? "Compare: SIM, são iguais" : "COmpare: NAO") << endl;

    return 0;
}
