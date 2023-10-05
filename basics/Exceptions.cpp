#include <iostream>
#include <locale.h>


void funcao(int *ptr, int x){
    if( ptr == NULL || x == 0){
        throw ptr;
        
    
    }else {
    std::cout << "O ponteiro é: " << *ptr << "e o numero é: " << x << '\n'; 
    }
    

}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL,"");
    int num = 10;
    int * ponteiro = nullptr;   
    try    {
     funcao(ponteiro,num);   
    }
    catch (...)    {
        std::cout << "Erro doido" << '\n';
    }
    
    return 0;
}
