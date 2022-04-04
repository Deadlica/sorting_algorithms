#include <iostream>
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
    measurements<int> tester(10);

    //Insertion sorts
    tester(INSERTION_SORT, RANDOM);
    tester(INSERTION_SORT, SORTED);
    tester(INSERTION_SORT, REVERSE_SORTED);
    tester(INSERTION_SORT, CONSTANT);

    //Selection sorts
    tester(SELECTION_SORT, RANDOM);
    tester(SELECTION_SORT, SORTED);
    tester(SELECTION_SORT, REVERSE_SORTED);
    tester(SELECTION_SORT, CONSTANT);

    //Quick sorts with right pivot
    tester(R_QUICK_SORT, RANDOM);
    tester(R_QUICK_SORT, SORTED);
    tester(R_QUICK_SORT, REVERSE_SORTED);
    tester(R_QUICK_SORT, CONSTANT);

    //Quick sorts with median of three pivot
    tester(MO3_QUICK_SORT, RANDOM);
    tester(MO3_QUICK_SORT, SORTED);
    tester(MO3_QUICK_SORT, REVERSE_SORTED);
    tester(MO3_QUICK_SORT, CONSTANT);

    //std::sort
    tester(STD_SORT, RANDOM);
    tester(STD_SORT, SORTED);
    tester(STD_SORT, REVERSE_SORTED);
    tester(STD_SORT, CONSTANT);
    return 0;
}