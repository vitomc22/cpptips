#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>
//Exemplo invocando um construtor de outro C++11
class Student {
    public:
       Student(const char *pName, int xfrHours, double xfrGPA)
       {
           std::cout << "Construindo student" << pName << std::endl;
           name = pName;
           semesterHours = xfrHours;
           gpa = xfrGPA;
       }
       //Basicamente aqui o objeto do main  "noName" chama o construtor padrão sem argumento"
       Student() : Student("No Name", 0, 0.0){} //depois ele chama o outro construtor 
                                                //para inicializar o resto dos atributos. 
                                                //com os valores padrões.
                                                //Afinal, o objeto da classe Student
                                                //ainda possui os atributos "semesterHours"
                                                // e também "GPA"
       Student(const char *pName) : Student(pName, 0, 0.0){}
       //Aqui o construtor faz a mesma coisa
       //Porem ja recebe o valor do ponteiro *pName
       //E chama o outro construtor com a inicialização dos outros atributos 

        
    protected:
        std::string name;
        int semesterHours;
        float gpa;

};

int main () 
{
    //isso invoca 3 contrutores diferentes
    Student noName;
    Student freshman ("Marian Haste!");
    Student xferStudent ("Pikup",80,2.5);

    std::cout << "Press enter to continue" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;

};