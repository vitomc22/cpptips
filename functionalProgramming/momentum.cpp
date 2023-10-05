//Deep Learning
//Momentum é uma extensão do algotitimo de otimização de descida gradiente que constrói inércia em uma direção de busca para superar
//mínimos locais de oscilação de gradientes ruidosos
#include<algorithm>
#include<iostream>
#include <vector>


int main(){
    auto momentun_optimizer = [V = std::vector<double>()] (const std::vector<double> &gradient) mutable{

        if (V.empty()) V.resize(gradient.size(),0.);
            std::transform(V.begin(),V.end(), gradient.begin(),V.begin(), [](double v, double dx){
                double beta = 0.7;
                return v = beta * v + dx;
        });
        return V;
       };

       auto print = [] (double d){std::cout << d << " ";};

       const std::vector<double> current_grads {1., 0., 1. , 1., 0., 1.};

       for(int i = 0; i < 3; i++){
            std::vector<double> weight_update = momentun_optimizer(current_grads);
            std::for_each(weight_update.begin(), weight_update.end(),print);
            std::cout << "\n";

       }

       return 0;



    }