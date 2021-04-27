#include <cstdio>
#include <iostream>
#include <cstdlib>

class NameDataSet
{
    public:
       std::string sName;

       NameDataSet* pNext;

};

//ponteiro para primeira entrada da lista
NameDataSet* pHead = nullptr;

//adiciona membro novo na lista ligada

void add(NameDataSet* pNDS)
{
    //aponta a entrada atual para o início da lista 
    pNDS->pNext = pHead;

    //aponta o ponteiro inicial para a entrada atual
    pHead = pNDS;
}
 // get data - lê nome
 //    retorna nulo se nao for ler mais

 NameDataSet* getData()
  {
         //le o primeiro nome
         std::string name;
         std::cout <<" Enter name";
         std::cin >> name;
     
           if (name == "exit")
           {
                  //retorna nulo para encerrar a entrada
                  return nullptr;
           } 

        //pega uma entrada nova e enche de valores
        NameDataSet* pNDS = new NameDataSet;
        pNDS->sName = name;
        pNDS->pNext = nullptr;
        //retorna o endereço do objeto criado
        return pNDS;   
  }

int main()
{
    std::cout << "Read names os estudents\n"
              << "Enter 'exit' for first name to exit"
              << std::endl;

              // cria  (outro) objeto NameDataSet
    NameDataSet* pNDS;
    while (pNDS = getData())
    {
        //adiciona ele á lista dos objetos NameDataSet
        add(pNDS);
    }

    //para exibir os objetos, itera a
    //lista (para quando o proximo endereço for NULL)
    std::cout << "\nEntries:" << std::endl;
    for (NameDataSet *pIter = pHead;
                      pIter; pIter = pIter->pNext)
    {
        // exibe o nome da lista atual
        std::cout << pIter->sName << std::endl;
    }                      
    //espera até o usuário estar pronto antes de encerrar o programa
    std::cout <<" pressione entrer para continuar" << std::endl;
    std::cin.ignore(10, '\n');
    std::cin.get();
    return 0;           
}