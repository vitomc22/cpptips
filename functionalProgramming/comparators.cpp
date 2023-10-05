#include <algorithm>
#include<functional>
#include<iostream>

int main(){
    std::vector<std::function<bool (double, double)>> comparators{
        std::less<double>(),
        std::less_equal<double>(),
        std::greater_equal<double>(),
        std::greater<double>()
    };

    double x = 10;
    double y = 10;

    auto compare = [&x, &y](const std::function<bool(double,double)> &comparator){ //funcao labda que faz a comparacao
        bool b = comparator(x, y);
        std::cout << (b ? "TRUE" : "FALSE") << std::endl;

    };

    std::for_each(comparators.begin(), comparators.end(), compare);//itera sobre os vetores de comparators

    return 0;
}

//OUTPUT...
//FALSE
//TRUE
//TRUE
//FALSE