#include <iostream>

class Primeira{
    public:
    Primeira(){
    std::cout <<"Iniciando a primeira" << '\n';
    }

    ~Primeira(){
        std::cout<<" destruindo primeira" << '\n';
    }

    void fmembro1(){
        std::cout <<"fmembro1 da primeira" << '\n';
    }

};

class Segunda{
    public:
    Segunda(){
    std::cout <<"Iniciando a segunda" << '\n';
    }

    virtual void f_membro_n_pode_ser_inst() = 0; //abstrata igualando a zero

    ~Segunda(){
        std::cout<<" destruindo segunda" << '\n';
    }

    void fmembro2(){
        std::cout <<"fmembro2 da segunda" << '\n';
    }

};

class Terceira : public Primeira, public Segunda{
    public:
    Terceira(){
    std::cout <<"Iniciando a terceira" << '\n';
    }

    virtual void f_membro_n_pode_ser_inst(){
        std::cout << "agora consigo usar a virtual" << '\n';
    };

    ~Terceira(){
        std::cout<<" destruindo terceira" << '\n';
    }

    void fmembro3(){
        std::cout <<"fmembro3 da terceira" << '\n';
    }

};


int main(int argc, char const *argv[])
{
    Terceira terceira;
    terceira.f_membro_n_pode_ser_inst();
    return 0;
}
