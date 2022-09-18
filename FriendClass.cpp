#include <iostream>
#include <string>
class Casa{
    public:
       std::string comp = "123";

    protected:
       char essid[5] = {'H','o','m','e','\0'};
    
    private:
       std::string passwd = "abc" + comp;

    friend class Vizinho;     

};
class Vizinho{
    public:
       void controller(){
        Casa c;
           std::cout << "Olá vizinho! O nome da rede é : " << c.essid << '\n';
           std::cout << "A senha é: " << c.passwd << '\n';
       }
};

int main(int argc, const char** argv) {
    Vizinho v;
    v.controller();
    return 0;
}