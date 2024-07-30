#include <algorithm>
#include<vector>
#include<iostream>
#include<functional>

auto partition = [](std::vector<int>& v, int low , int high) {
    int pivot = v[high];
    int i = (low - 1);

    for (int j = low; j < high; ++j) {
        if (v[j] <= pivot) {
            ++i;
            std::swap(v[i], v[j]);
        }
    }
    std::swap(v[i + 1], v[high]);
    return (i + 1);
};

std::function<void(std::vector<int>& v, int low, int high)> 
quick_sort = [](std::vector<int>& v, int low, int high) {
    if(low < high){
        int p = partition(v,low,high);
        quick_sort(v, low, p - 1);
        quick_sort(v, p + 1, high);
    }
};

int main (){
    std::vector<int> numbers = {11,2,13,17,12,8,4,8,9,9,9,8,8};
    quick_sort(numbers, 0, numbers.size()-1);
    std::for_each(numbers.begin(), numbers.end(), [](int num) { std::cout << num << " "; });
    return EXIT_SUCCESS;
}

//to run with wall flags:
// clang++ -g -Wall -Wextra -Wpedantic -fsanitize=address quick_sort.cpp 