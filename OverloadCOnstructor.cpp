#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string.h>

class Student {
    public:
       Student()
        {  
           std::cout << "contruindo student No Name" << std::endl;
           name = "No Name";
           semesterHours = 0;
           gpa = 0.0;
        }

        Student (const char *pName)
        {
            std::cout << "Construindo student" << pName << std::endl;
            name = pName;
            semesterHours = 0;
            gpa = 0;
        }

        Student (const char *pName, int xfrHours, float xfrGPA)
        {
            std::cout << "contruindo student" << pName << std::endl;
            name = pName;
            semesterHours = xfrHours;
            gpa = xfrGPA;
        }
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