//Herança míltipla
#include <cstdio>
#include <iostream>
#include <cstdlib>

class Bed
{
    public:
       Bed(){}
       void sleep() {std::cout << "Dormindo" << std::endl;}
};

class Sofa
{
    public:
       Sofa(){}
       void watchTV(){std::cout << "Ver TV" << std::endl;}
       int weight;
};

//SleeperSofa sofá cama
class SleeperSofa : public Bed, public Sofa
{
    public:
       SleeperSofa(){}
       void foldOut(){std::cout << "Desdobrar" << std::endl;}
};

int main(int argc, char const *argv[])
{
    SleeperSofa ss;
    //voce pode assistir tv em um sofá cama like sofa
    ss.watchTV();//Sofa::watchTV
    // e tambem desdobrar
    ss.foldOut(); //SleeperSofa::foldOut
    //e também dormir
    ss.sleep(); //Bed::sleep
    
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;
}
