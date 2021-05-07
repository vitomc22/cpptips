#include <iostream>
#include <cstdio>
#include <cstdlib>

class Student
{
    public:
       //construtor convencinal
       Student (const char *pName = "no name", int ssId =0)
       : name(pName), id(ssId)
       {std::cout << "Constructed" << name << std::endl;}

       //contrutor de cópia
       Student (const Student& s)
       : name("Copy of " + s.name), id(s.id)
       {std::cout << "Constructed" << name << std::endl;}
       ~Student() {std::cout << "Destruindo" << name << std::endl;}

       protected:
       std::string name;
       int id;
};

//fn recebe seu argumento por valor
void fn (Student copy)
{
    std::cout <<"In function fn()" << std::endl;
}

int main ()
{
  Student scruffy("Scruffy", 1234);
  std::cout <<"Calling fn()" << std::endl;
  fn(scruffy);
  std::cout<<"Back in main()" <<std::endl;


  std::cout <<"Press enter to cintinue" << std::endl;
  std::cin.ignore(10,'\n');
  std::cin.get();
  return 0;
}