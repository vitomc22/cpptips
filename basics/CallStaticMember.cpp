#include <iostream>
#include<cstdio>
#include<cstdlib>

class Student
{
    public:
       Student(const char* pN = "No name") : sName(pN)
       {
           noOfStudents++;
       }
       ~Student() { noOfStudents--; }
       const std::string& name() {return sName;}
       static int number() {return noOfStudents;}

    protected:
       std::string sName;
       static int noOfStudents;
};

int Student::noOfStudents = 0;

 
int main() {
    Student s1("Chester");
    Student* pS2 = new Student ("Scooter");


    std::cout << "Created" << s1.name()
              << "and" << pS2->name() << std::endl;
    std::cout << "Number of students is"
              << s1.number() << std::endl;

              std::cout << "Deleting" << pS2->name() << std::endl;
              delete pS2;

    std::cout << "Number of students is" << Student::number() << std::endl;

    std::cout << "Press enter to continue..." << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();        
    return 0;
}
