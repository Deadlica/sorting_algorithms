//
// Created by samuel on 3/29/22.
//

#ifndef DATA_GENERATION_H
#define DATA_GENERATION_H

#include <ctime>
#include <cmath>
#include <vector>
#include <algorithm>

enum order {RISING, FALLING};

template<typename T>
std::vector<T> generateRandom(T size) {
    std::vector<T> container;
    T element;
    for(size_t i = 0; i < size; i++) {
        element = std::rand();
        element = fmod(element, size + 1);
        container.push_back(element);
    }
    return container;
}

template<typename T>
std::vector<T> generateOrder(T size, order order = RISING) {
    std::vector<T> container;
    /*T element = std::rand();
    element = fmod(element, size + 1);
    for(size_t i = 0; i < size; i++) {
        container.push_back(element);
        T temp = std::rand();
        temp = fmod(temp, size) + 1;
        element += temp;
    }*/
    for(size_t i = 0; i < size; i++) {
        container.push_back(i + 1);
    }
    if(order == FALLING) {std::reverse(container.begin(), container.end());}
    return container;
}

template<typename T>
std::vector<T> generateConstant(T size) {
    std::vector<T> container;
    T element = std::rand();
    element = fmod(element, size + 1);
    for(size_t i = 0; i < size; i++) {
        container.push_back(element);
    }
    return container;
}

#endif
