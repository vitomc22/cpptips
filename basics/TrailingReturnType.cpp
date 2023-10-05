#include <ostream>
#include <stdio.h>
#include <iostream>
#include <type_traits>

// Trailing return type is used to represent 
// a fully generic return type for a+b.

//cpp11
template <typename FirstType , typename SecondType>
auto add(FirstType a ,SecondType b) -> decltype(a+b){
    return a+b;
}

//cpp14

template <typename Ft , typename St> decltype(auto)
ad(Ft a ,St b){
    return a+b;
}



int main(){
   //CPP11
   // The first template argument is of the integer type, and
   // the second template argument is of the character type.
   auto first = add(1, 'A');

   // Both the template arguments are of the integer type.
   auto second =  add(3, 5);

   std::cout << first << '\n'; // result 66

   std::cout << second << '\n'; // result 8

    
    //CPP14
    // The first template argument is of the integer type, and
   // the second template argument is of the character type.
   auto ft = ad(1, 'A');

   // Both the template arguments are of the integer type.
   auto sc =  ad(3, 5);

   std::cout << ft << '\n'; // result 66

   std::cout << sc << '\n'; // result 8

}