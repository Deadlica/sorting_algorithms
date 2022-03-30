#include <iostream>
#include <vector>
#include "algorithms.h"
#include "data_generation.h"

int main() {
    std::srand((unsigned) std::time(0));
    std::vector<double> arr = generateRandom(11.0);
    quick_sort(arr.begin(), arr.end(), MEDIAN_OF_THREE);
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i] << ", ";
    }
    std::cout << std::endl;
    return 0;
}
