#include <algorithm>
#include<iostream>
#include<stdio.h>
#include <vector>

double square(double x) { return x * x; }

int main(){
    std::vector<double> X  {1.,2.,3.,4.,5.,6.};
    std::vector<double> Y (X.size(), 0);

    std::transform(X.begin(), X.end(), Y.begin(), square);
    std::for_each(Y.begin(), Y.end(), [] (double y) {std::cout << y << std::endl;});

    return 0;
}