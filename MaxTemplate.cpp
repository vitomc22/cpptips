//exemplo de template max()
#include <iostream>
#include <cstdio>
#include <cstdlib>

template <class T> T maximum(T t1, T t2)
{
    return (t1 > t2) ? t1 : t2;  // operador ternário retorna t1 se true, retorna t2 se false
}
int main(int argc, char const *argv[])
{
    //encontra o máximo de dois ints
    //aqui c++ cria maximum (int, int)
    std::cout << "maximum (-1, 2) = " << maximum (-1, 2) << std::endl;
    //repete para dois doubles;
    //neste caso, nós temos que fornecer T explicitamente
    //já que os tipos de argumentos são diferentes
    std::cout << "maximum (1, 2.5) = " << maximum<double> (1, 2.5) << std::endl;

    std::cout << "press enter to continue" << std::endl;
    std::cin.ignore(10, '\n');
    std::cin.get();  
    return 0;
}
