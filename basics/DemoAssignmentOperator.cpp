#include<iostream>
#include<cstdlib>
#include<stdlib.h>


class DArray
{
    public:
    DArray(int nLenghtOfArray = 0)
    : nLenght(nLenghtOfArray), pArray(nullptr)
       {
           std::cout << " Creating DArray os Lenght = ";
           if (nLenght > 0)
           {
               pArray = new int[nLenght];
           }
           
       }
    DArray (DArray& da)
    {
        std::cout << "Copyng DArray of lenght = "
                  << da.nLenght << std::endl;
                  copyDArray(da);
    }
    ~DArray()
    {
        deleteDArray();
    }
    // Operador de atribuição
    DArray& operator= (const DArray& s)
    {
        std::cout << "Assigning source of lenght = "
                  << s.nLenght
                  << " to target of lenght = "
                  << this -> nLenght << std::endl;
            //apaga as coisas existentes
            deleteDArray();
            //... antes de substituir por outras coisas 
            copyDArray(s);
            //retorna a referencia ao objeto existente
            return *this;      
    }
    int& operator[] (int index)
    {
        return pArray [index];
    }

    int size() {return nLenght;}

    void display (std::ostream& out)
    {
       if (nLenght > 0)
       {
           out << pArray[0];
           for (int i = 1; i < nLenght; i++)
           {
               out << ", " << pArray[i];
           }
           
       }
       
        
    }

    protected:
    void copyDArray (const DArray& da);
    void deleteDArray();
    

    int nLenght;
    int* pArray;
};

// Cria uma cópia de um array dinâmico de ints 
void DArray::copyDArray(const DArray& source)
{
    nLenght = source.nLenght;
    pArray = nullptr;
    if (nLenght > 0)
    {
        pArray = new int [nLenght];
        for (int i = 0; i < nLenght; i++)
        {
            pArray[i] = source.pArray[i];
        }
        
    }
    
}
//deleteDArray() - retorna memória para o heap
void DArray::deleteDArray()
{
    nLenght = 0;
    delete pArray;
    pArray = nullptr;
}

 
int main(int argc, char const *argv[]) {
    //um array dinâmico e atribui a ele
    DArray da1(5);
    for (int i = 0; i < da1.size(); i++)
    {
        //utiliza o operador de índice definido pelo
        //usuário para acessar membros do array 
        da1[i] =i;
    }
    std::cout << "da1="; da1.display(std::cout); std::cout << std::endl;
    //agora cria uma cópia desse array dinâmico usando o construtor de cópia
    //isso é o mesmo que da2(da1)
    DArray da2 = da1;
    da2[2] = 20; //modifica o valor na cópia
    std::cout << "da2="; da2.display(std::cout); std::cout << std::endl;
    //sobrescreve da2 existente com da1 original
    da2 = da1;
    std::cout << "da2="; da2.display(std::cout); std::cout << std::endl;

    std::cout << "Press enter to continue";
    std::cin.ignore(10,'\n');
    std::cin.get();
 
 return 0;
}