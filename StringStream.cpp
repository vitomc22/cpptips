// lê e analisa o conteúdo de um arquivo 
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<sstream>
//ParserAccountInfo - lê um buffer passado como se fosse um arquivo real 
// name, account balance
//retorna true se tudo funcionar bem

bool parseString( const char* pString,
                  char* pName, int arraySize,
                  long& accountNum, double& balance)
{
                               //associa um objeto istrstream com a string de caractere de entrada
    std::istringstream inp (pString);
                               //Lê a vírgula separadora
    inp.getline(pName, arraySize,',');
                               //agora o número da conta
    inp >> accountNum;
                               //agora o saldo
    inp >> balance;
                               //retorna o status de erro 
    return !inp.fail();                                                                                                                                                       
}
int main(int nNumberofArgs, char  *pszArgs[])
{
 //deve fornecer o nome do aquivo
 char szFileName[128];
std::cout << "Enter de name of file:";
std::cin.getline(szFileName,128);
//Pega o fluxo do arquivo 
std::ifstream* pFileStream = new std::ifstream(szFileName);
if (!pFileStream->good())
{
    std::cerr << "Can't open" << pszArgs[1] << std::endl;
    return 0;
}  
   // le uma linha fora do arquivo , analisa e exibe resutados
   for (int nLineNum = 1;;  nLineNum++)
   {
       char buffer[256];
       pFileStream->getline(buffer,256);
       if (pFileStream->fail())
       {
           break;
           std::cout << nLineNum << ":" << buffer << std::endl;

           //analisa campos individuais
           char name[80];
           long accountNum;
           double balance;
           bool result = parseString(buffer,name,80,accountNum,balance);
           if (result == false)
           {
            std::cout << "Error no retorno de parseString\n" << std::endl;
            continue;
           }

        //exibe como saída os campos que analisamos
        std::cout << "Read the following fields:" << std::endl;
        std::cout << name << "name" << "\n";
        std::cout << accountNum << "accountNum" << "\n";
        std::cout << balance << "balance" << std::endl;   
       //coloca os campos juntos novamente em ordem diferentes (inserindo ends////// 
       //certifica que o buffer é terminado em zero )
       std::ostringstream out;
       out << name << ","
           << balance << " "
           << accountNum << std::ends;

           std::string oString = out.str();
           std::cout << "Recorded fields: " << oString << std::endl;
       }
       

   }
   std::cout << "Enter to continue..." << std::endl;
   std::cin.ignore(10,'\n');
   std::cin.get();
    return 0;
}
                  