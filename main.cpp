#include <iostream>
#include <vector>
#include "algorithms.h"
#include "data_generation.h"
#include "timer.h"
#include "measurements.h"

template<typename T>
void print(T first, T last) {
    for(;first != last; first++) {
        std::cout << *first;
        if(first + 1 != last) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main() {
    std::srand((unsigned) std::time(0));
    std::vector<int> arr = generateOrder(20000, FALLING);
    //print(arr.begin(), arr.end());
    //quick_sort(arr.begin(), arr.end(), MEDIAN_OF_THREE);
    //print(arr.begin(), arr.end());
    //alg::is_sorted(arr.begin(), arr.end());
    measurements<float> temp(10);
    temp(MO3_QUICK_SORT, RANDOM);
    return 0;
}