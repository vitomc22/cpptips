#include<iostream>
#include<stdio.h>

template<class T> T maximum(T t1, T t2)
{
    return (t1> t2) ? t1 : t2;
}

int main (int argc, char const *argv[])
{
    std::cout << maximum(12.1, 17.8);
}