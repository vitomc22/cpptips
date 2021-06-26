// implementa vetor que usa um tipo de modelo
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "templatevector.h"
//intFn() manipula uma coleção de inteiros

void intFn()
{
    //cria um vetor de inteiros
    TemplateVector <int> integers(10);
    //adiciona valores ao vetor
    std::cout << "Enter integer values to add to a vector\n"
              << "(Enter a negative number to terminate) :"
              << std::endl;
    for(;;)
    {
        int n;
        std::cin >> n;

        if (n < 0) {break;}
        integers.add(n);        
    }          
    std::cout << "\nHere are the numbers you entered: " << std::endl;
    for (int i = 0; i < integers.size(); i++)
    {
        std::cout << i << ";" << integers.get() << std::endl;
    }
}

//Names - cria e manipula um vetor de nomes
class Name
{
    public:
       Name() = default;
       Name(std::string s) : name(s){}
       const std::string& display() {return name;}
    protected:
       std::string name;   
};

void nameFn()
{
    //cria um vetor Name de objetos
    TemplateVector<Name> names (20);
    //adiciona valores ao vetor
    std::cout << "Enter names to add to a second vector\n"
              << "(Enter an 'x' to quit) : " << std::endl;
    for(;;)
    {
        std::string s;
        std::cin >> s;
        if (s == "x" || s == "X") {break;}
        names.add(Name(s));
    }
    std::cout << "\nHere are the names you entered" << std::endl;
    for(int i = 0; i < names.size(); i++)
    {
        Name& name = names.get();
        std::cout << i << ":" << name.display() << std::endl;
    }          
}
int main(int argc, char const *argv[])
{
    intFn();
    nameFn();

    std::cout << "press enter to continue..." << std::endl;
    std::cin.ignore();
    std::cin.get();
    return 0;
}
