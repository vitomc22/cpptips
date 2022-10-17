#include <iostream>

struct  Estrutura{
    int operator() (int x) const{
        return x *2;
    }    
};


int main(int argc, char const *argv[]){
    Estrutura e;
    int x = e(5);
    std::cout << "O valor de X é : " << x << '\n';
    return 0;
}

