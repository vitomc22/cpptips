#include <iostream>
#include <cstdio>
#include <cstdlib>

class Student 
{
    public:
    int semesteHours;
    double gpa;
};

void someFn (Student& refS)
{
    refS.semesteHours = 10;
    refS.gpa = 3.0;
    std::cout <<"o valor de GPA =" <<refS.gpa<< std::endl;
}

int main ()
{
    Student s;
    s.gpa =0.0;
    std::cout << "O valor de s.gpa=" << s.gpa << std::endl;
    std::cout << "chamando someFn(Student*)" << std::endl;
    someFn(s);
    std::cout << "Retornando de someFn (Student&)" << s.gpa << std::endl;

    std::cout << "o valor de s.gpa" << s.gpa << std::endl;

    std::cout << "enter para finalizar" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;

}