//Faz backup dos arquivos passados para o programa
#include<iostream>
#include<cstdio>
#include<fstream>
#include<cstdlib>

int main(int nNumberofArgs, char* pszArgs[])
{
    //repete o processo para cada arquivo passado 
    for (int n = 1; n < nNumberofArgs; n++)
    {
        //cria o nome do arquivo e um nome ".backup"
        std::string szSource(pszArgs[n]);
        std::string szTarget = szSource + ".backup";

        //agora abra a fonte para ler o alvo para escrever
        std::ifstream input(szSource.c_str(), 
        std::ios_base::in | std::ios_base::binary | std::ios_base::trunc);

        std::ofstream output (szTarget.c_str(),
        std::ios_base::out | std::ios_base::binary | std::ios_base::trunc);

           if (input.good() && output.good())
           {
               std::cout << "Backing up" << szSource << "...";
               //lê e escreve 4 blocos até um erro ocorrer ou o arquivo chegar em EOF
               while (!input.eof() && input.good())
               {
                   char buffer[4096];
                   input.read(buffer,4096);
                   output.write(buffer, input.gcount());
               }

               std::cout << "finished" << std::endl;            

           }

           else
           {
               std::cerr << "couldn't copy " << szSource << std::endl;
           }
    }
    
    std::cout << "Press enter to continue" << std::endl;
    std::cin.ignore(10, '\n');
    std::cin.get();
    return 0;
}
