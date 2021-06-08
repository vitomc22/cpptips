//entrada de arquivo através do fstream
#include<cstdio>
#include<cstdlib>
#include<fstream>
#include<iostream>

std::ifstream& openFile()
{
    std::ifstream* pFIleStream = 0;
    for(;;)
    {
        //abre o aquivo especidicado pelo usuário
        std::string sFileName;
        std::cout << "Enter the name os a file with integers:";
        std::cin >> sFileName;
        //abre o arquivo para leitura
        pFIleStream = new std::ifstream(sFileName.c_str());
        if (pFIleStream->good());
           {
               pFIleStream->seekg(0);
               std::cerr << "Successfully opened "
                         << sFileName << std::endl;
                break;         
           }
           std::cerr << "Couldn't open" <<sFileName << std::endl;
           delete pFIleStream;
    }
    return *pFIleStream;
}

int main(int argc, char const *argv[]) {
    //pega arquivo de fluxo
    std::ifstream& fileStream = openFile();
    //para quando não há mais dados no arquivo
    while (!fileStream.eof())
    {
        //lê valor
        int nValue = 0;
        fileStream >> nValue;

        //para se a leitura do arquivo falhou 
        //provavelmente se algo no arquivo nao for int
        if (fileStream.fail())
        {
            break;
        }
        //exibe a saída do valor lido
        std::cout << nValue << std::endl;
    }
    
    std::cout << "Press enter to continue" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;
}
