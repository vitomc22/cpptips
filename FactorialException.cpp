//exemplo de exceções usando uma função fatorial
#include<cstdio>
#include<iostream>
#include<cstdlib>

// factorial - computa fatorial 
int factorial (int n)
{
    //voce nao pode manipular valores negativos
    //de n; melhor checar a condição primeiro
    if (n < 0)
    {
        throw std::string("argumento para fatorial negativo");
    }
    
    // siga em frente e calcule o fatorial
    int accum = 1;
    while (n > 1)
    {
        accum *= n;
        n--;
    }
    return accum;
    
}
int main(int argc, char const *argv[])
{
    try 
    {
        //isso funfa
        std::cout << "Fatorial de 3 é "
                  << factorial(3) << std::endl;
        //isso gerará excessão
        std::cout << "Fatorial de -1 é "
                  << factorial(-1) << std::endl;
        //o controle jamais chegará aqui
        std::cout << "Fatorial de 5 é "
                  << factorial(5)  << std::endl;                   
    }
        //o controle passa aqui
        catch(std::string error)
        {
            std::cout << " Ocorreu um erro: " << error << std::endl;
        }
        catch(...)
        {
            std::cout << "Catch padrão" << std::endl;
        }

std::cout << "Press enter to continue..." << std::endl;
std::cin.ignore(10, '\n');
std::cin.get();
    return 0;
}
