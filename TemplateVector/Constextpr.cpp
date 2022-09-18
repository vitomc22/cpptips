#include <iostream>

//molhera o desempenho de calculos e expressoes numéricas em tempo de compilação 
constexpr long int fib(int n){
    return (n <= 1) ? n : fib(n - 1) + fib(n - 2);
}

int main(int argc, char const *argv[])
{
    auto f = fib(30); 
    std::cout <<"Número fibonacci de 30  é: " << f << '\n';
    return 0;
}
