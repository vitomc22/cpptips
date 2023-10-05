#include <cstddef>
#include <cstring>
#include <iostream>
//A simple form to parse objects with token
int main (){

std::string str = "numero = 3 + 6 \n nome='victor'";

char * pstr = nullptr;

pstr = std::strtok(&str[0]," =");

while (pstr!= NULL) {
    std::cout << pstr << std::endl;
    pstr = std::strtok(NULL," =");
}

std::cout << pstr;
    return 0;
}