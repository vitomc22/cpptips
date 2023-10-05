#include <iostream>
#include <list>
#include <cstdio>
#include <cstdlib>

class Student
{
       public:
          Student(const char* psZs, int id)
          : sName(psZs), ssID(id){}
          std::string sName;
          int ssID;
};

//função para suportar odernação
bool operator < (const Student& s1, const Student& s2)
{
    return s1.ssID < s2.ssID;
}

//itera a lista exibindo cada elemento
void displayStudents (std::list<Student>& students)
{
    //aloca o iterador que aponta para o primeiro elemento na lista
    //list<Student>::interator iter = students.begin();
    auto iter = students.begin();
    //continua o loop na lista até o iterator chegue ao final da lista
    while(iter != students.end())
    {
        //recupera o Student para onde o iterator aponta
        Student& s = *iter;
        std::cout << s.ssID << " - " << s.sName << std::endl;
        //agora move o iterator para o próximo item da lista
        iter++;
    }
}
int main(int argc, char const *argv[])
{
    //define uma coleção de alunos
    std::list<Student> students;
    //adiona tres objetos Students a lista
    students.push_back(Student("Vitao Boladao,", 10));
    students.push_back(Student("Vitao Doido,", 5));
    students.push_back(Student("Vitao Lunus,", 15));
    //exibe a lista
    std::cout << "A lista original:" << std::endl;
    displayStudents(students);
    //agora ordena a lista e exibe de novo
    students.sort();
    std::cout <<" Essa é a lista ordenada:" << std::endl;
    displayStudents(students); 
    
    std::cout << "press enter to continue..." << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();

    return 0;
}
