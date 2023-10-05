#include<cstdio>
#include<iostream>
#include<cstdlib>

class Person
{
    public:
    Person(const char *pN)
    {
        pName = new std::string(pN);
        std::cout << "Constructing" << *pName << std::endl;
    }
    Person(Person& p)
    {
        std::cout << "Copyng" << *p.pName << std::endl;
        pName = new std::string ("Copy of");
        *pName += *p.pName;
    }
    Person(Person&& p)
    {
        std::cout<< "moving" << *p.pName << std::endl;
        pName = p.pName;
        p.pName = nullptr;
    }
    ~Person()
    {
        if (pName)
        {
            std::cout << "Destructing"<< *pName << std::endl;
            delete pName;
        }
        else
        {
            std::cout << "Destructing null object" << std::endl;
        }
        
    }
    protected:
      std::string *pName;
};
Person fn2(Person p)
{
    std::cout << "Entering fn2" << std::endl;
    return p;
}
Person fn1(char* pName)
{
    std::cout << "Entering fn1_" << std::endl;
    return fn2 (*new Person(pName));

}

int main()
{
    Person s (fn1("Scrufy"));
    std::cout << "press enter to continue..." << std::endl;
    std::cin.ignore(10,'\n');
    std::cin.get();
    return 0;


}


   