#include <cstdlib>
#include <iostream>
#include <cstdio>

class Student
{
    public:
       Student (const char* pName)
       {
           std::cout << "construindo student" << pName << std::endl;
           name = pName;
           semesterHours = 0;
           gpa = 0.0;
       }                    //posso definir os tipos de variáveis no protected e deixar sem tipo no public
    protected:
       std::string name;
       int semesterHours;
       double gpa;    
};


int main()
{
    //cria aluno localmente e outro  no heap 
    Student s1("jack");
    Student* pS2 = new Student ("Scruffy");
    //garante que vai apagar aluno do heap
    delete pS2;
    std::cout<< "press enter to continue" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0; 
}
