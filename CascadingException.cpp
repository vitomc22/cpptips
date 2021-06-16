//Exemplo de desenrolar de pilha
#include<iostream>
#include<cstdio>
#include<cstdlib>

// protótipos de algumas funções

void f1();
void f2();
void f3();

class Obj
{
    public:
       Obj(char c) : label(c)
          {
              std::cout << "construindo objeto" << label << std::endl;
          }
          ~Obj()
          {
              std::cout << "destruindo objeto" << label << std::endl;
          }
    protected:
        char label;      
};

int main(int argc, char const *argv[])
{
    f1();
    //final do main
    std::cout << "Pressione enter para continuar" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;
}

void f1()
{
    Obj a('a');
       try
          {
              Obj b('b');
              f2();
          }
        catch(float f)
        {
            std::cout << "Float catch" << std::endl;
        }
        catch( int i)
        {
            std::cout << "Int catch" << std::endl;
        }
        catch(...)
        {
            std::cout << std::string("Generic catch") << std::endl;
        }  
}

void f2()
{
    try
    {
        Obj c('c');
        f3();
    }
    catch(std::string msg)
    {
        std::cout << "String catch" << std::endl;
    }
}
void f3()
{
    Obj d('d');
    throw 10;
}
