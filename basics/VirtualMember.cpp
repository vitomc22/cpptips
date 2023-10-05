#include <iostream>

class Mae{
    public:
      virtual void mensagem(){
        std::cout << "Eu sou a mãe" << '\n';
       }
};

class Filha : public Mae{
    public:
       void mensagem(){
        std::cout << "Eu sou a filha" << '\n';
       }
};

class Neta : public Filha{
    public:
       void mensagem(){
        std::cout << "Eu sou a neta" << '\n';
       }
};

void responde( Mae * m){
    m->mensagem();

}

int main(int argc, const char** argv) {
Mae m;
Filha f;
Neta n;

m.mensagem();
f.mensagem();
n.mensagem();

std::cout << "\n-----------------------\n";
responde(&m);
responde(&f);
responde(&n);

    return 0;
}