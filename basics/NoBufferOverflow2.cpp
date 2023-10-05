//usando budde de tamanho variável
#include <iostream>
#include <cstdlib>
#include <vector>
#include <fstream>
#include <cstring>
#include <string>
#include <cstdio>

// getstring - le uma string de entrada do user e a retorna para o chamador
char* getString(std::istream& cin)
{
    //cria um buffer de tamanho variável
    //tamanho inicial de 64 caracteres
    std::vector<char> buffer;
    buffer.reserve(64);

    //insere uma  string a partir do arquivo
    for (;;)
    {
        //le o próximo caractere
        char c = cin.get();

        //sai do loop se ler NULL ou EOF
        if ((c == 0 || cin.eof()))
        {
            break;
        }
        //adiciona caractere ao buffer e aumenta o buffer se necessário para acomodá-lo
        buffer.push_back(c);
    }
    //certifica que o buffer é terminado em nulo
    buffer.push_back('\0');

    //retorna uma cópia da string para o chamador
    char* pB = new char[buffer.size()];
       if (pB != nullptr)
       {
           strcpy(pB, buffer.data());
       }
       return pB;
}


int main(int argc, char const *argv[]) {
    //pega o nome fo arquivo a ser lido
    std::cout << "This program reads input from an input file \n"
                  "Enter the name of file: ";
    std::string sName;
    std::cin >> sName;

    //abre arquivo
    std::ifstream c(sName.c_str());
       if (!c)
       {
           std::cout << "\nError opening input file" << std::endl;
           exit(-1);
       }
       //le o conteudo do aqruivo para uma estring 
       char* pB = getString(c);
       //exibe
       std::cout << "\nWe successfuly read in:\n" << pB << std::endl;
    
    
    std::cout << "Press enter to continue" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    printf("Done!");
    exit(0);                         
    return 0;
}

   
   