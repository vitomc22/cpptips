#include <iostream>
#include <cstring>
#include <string>


template<class T>
 class Stack{
    public:
       void pilha(T array, int max){
           int i = {0};
           

           while (i < max) {
           std::cout<<"Os elementos do array são: " << array[i] << '\n';
           ++i;
           }


       }
};
int main(int argc, const char** argv) {
    Stack<const std::string*> s;
    //char marray[] = {'a','b','c','d','f','g'};
    std::string marray[] = {"JavaScript","é","safadeza","bagulho","é","tipagem estática"};
    int max = sizeof(marray) / sizeof(marray[0]);
   std::string* pmarray = marray;
    s.pilha(marray,max);
    return 0;
}