//criando classe de exceção personalizada

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <sstream>

class MyException
{
    public:
       MyException(const char* pMsg, int n,
                   const char* pFunc, 
                   const char* pFile, int nLine)
            : msg(pMsg), errorValue(n),
              funcName(pFunc), file(pFile), lineNum(nLine){}

        virtual std::string display()
        {
            std::ostringstream out;
            out << "Error <" << msg << ">"
                << " - value is " << errorValue << "\n"
                << "in function " << funcName << "() \n"
                << " line #" << lineNum << std::ends;
            return out.str();    
        }             
    protected:
        //mensagem de erro
        std::string msg;
        int errorValue;
        //nome da função, nome do arquivo e numero da linha onde ocorreu o erro 
        std::string funcName;
        std::string file;
        int lineNum;
};

// factorial - computa fatorial 
int factorial (int n) throw(MyException)
{
    //voce pode manipular valores negativos
    //de n; melhor verificar a condição primeiro
    if (n < 0)
    {
        throw MyException("Negative argument not allowed", n, __func__, __FILE__, __LINE__);
                                                              //Essas bostas aqui são #define intrínsecos que são ajustados para
                                                              //o nome do arquivo-fonte __FILE__, para número de linha atual naquele arquivo__LINE__ 
                                                              //e para o nome da funcao atual __func__ 
    }
    //continue e calcule fatorial
    int accum = 1;
    while (n > 0)
    {
        accum *= n;
        n--;
    }
    return accum; 
}
int main(int argc, char const *argv[])
{
    try 
    {
        //into funcionará
        std::cout << "factorial of 3 is "
                  << factorial(3) << std::endl;

        //aqui da pau exception
        std::cout << "factorial of -1 is "
                  << factorial(-1) << std::endl;

                  //aqui o controle nem chega
        std::cout << "factorial of 5 is "
                  << factorial(5) << std::endl;
                  
    }
    // o controle passa aqui
    catch (MyException e)
    {
        std::cout << e.display() << std::endl;
    }
    catch(...) //catch padrão dessa merda
    {
        std::cout << "Default catch" << std::endl;
    }
    std::cout << "Press enter to continue..." << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;
}

