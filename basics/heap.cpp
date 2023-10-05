#include <iostream>
#include <memory>

int main()
{
   auto a = std::make_unique<int>(7);
 
   std::cout << "a = " << *a << std::endl;

   // A variável `a` será deletada automaticamente quando o escopo terminar
}
