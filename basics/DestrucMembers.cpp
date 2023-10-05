#include <cstdio>
#include <cstdlib>
#include <iostream>

class Course 
{
    public:
       Course() { std::cout << "contruindo course" << std::endl;}
      ~Course() { std::cout << "destruindo course" << std::endl;}
};

class Student
{
    public:
       Student() { std::cout << "construindo student" << std::endl;}
       ~Student() { std::cout << "destruindo student" << std::endl;}
};

class Teacher
{
    public:
       Teacher()
       {
           std::cout << "contruindo teacher" << std::endl;
           pC = new Course;
       }
       ~Teacher()
       {
           std::cout << "destruindo teacher" << std::endl;
           delete pC;
       }
    protected:
       
           Course* pC;
};

class TutorPair
{
    public:
       TutorPair() {std::cout << "construindo tutorpair" << std::endl;}
       ~TutorPair() {std::cout << "destruindo tutorpair" << std::endl;}
    protected:
       Student student;
       Teacher teacher;
};

TutorPair* fn()
{
    std::cout << "criando objeto tutorpair na funcao fn()" <<std::endl;
    TutorPair tp;

    std::cout << "alocando tutorpair na heap" << std::endl;
    TutorPair* pTP = new TutorPair;

    std::cout << "Retorando de fn()" << std::endl;
    return pTP;
}

int main ()
{
    TutorPair* pTPReturned = fn();
    std::cout << " Return heap object to the heap" << std::endl;
    delete pTPReturned;
    std::cout << "press enter to continue" << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;

}

