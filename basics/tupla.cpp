#include<iostream>
#include<tuple>
#include <vector>

int main(int argc, char const *argv[])
{
    //declarando uma tupla
    std::tuple<char, int, float> geek;

    //adicionando valores a tupla unsando make_tuple()
    geek = std::make_tuple('a',10,15.5);

    //printando valores da tupla com get()
    std::cout << "Tamanho da tupla: " << std::tuple_size<decltype (geek)>::value << '\n';

   auto size_tuple = std::tuple_size<decltype (geek)>::value;

   std::cout <<" Valores da tupla: " << std::get<0>(geek) << ", " << std::get<1>(geek)<< ", " << std::get<2>(geek);
    
    
    return 0;
}
