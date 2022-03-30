//
// Created by samuel on 3/29/22.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>

enum pivot {MEDIAN_OF_THREE, RIGHT_ELEMENT};

template<typename T>
T partition(T first, T last) {
    T pivot = last;
    T it = first - 1; //outside of array
    for (T current = first; current != last; current++) {
        if (*current < *pivot) { //Iterating, checking if elements are less that pivot
            it++;
            std::iter_swap(it, current); //Puts lower than pivot elements at the front of the array
        }
    }
    std::iter_swap(++it, pivot);
    return it;
}

template<typename T>
T find_median_pivot(T first, T middle, T last) {
    if((*first < *middle && *middle < *last) ||  (*last < *middle && *middle < *first)) { //middle is the median
        if(*first > *last) {
            std::iter_swap(first, last); //first and last are in the wrong order
        }
    }
    else if((*middle < *first && *first < *last) || (*last < *first && *first < *middle)) { //first is the median
        if(*middle > *last) {
            std::iter_swap(middle, last); //middle and last are in the wrong order
        }
        std::iter_swap(first, middle); //Puts median in the middle
    }
    else { //last is the median
        if(*first > *middle) {
            std::iter_swap(first, middle); //first and middle are in the wrong order
        }
        std::iter_swap(middle, last); //Puts median in the middle
    }
    return middle; //Returns the pivot
}

template<typename T>
void insertion_sort(T first, T last) {
    T key, prev;
    for(auto current = first + 1; current != last; current++) {
        key = current;
        prev = current - 1;
        for(;*key < *prev && prev != first - 1; key--, prev--) {
            std::iter_swap(key, prev);
        }
    }
}

template<typename T>
void selection_sort(T first, T last) {
    for(;first !=  last; first++) {
        auto min = std::min_element(first, last);
        std::iter_swap(first, min);
    }
}

template<typename T>
void quick_sort(T first, T last, pivot method) {
    if (first == last || first == last - 1) { return; }
    T pivot;
    switch (method) {
        case RIGHT_ELEMENT:
            pivot = last - 1; //Furthest right element
            break;
        case MEDIAN_OF_THREE:
            T middle = first + (last - first) / 2;
            pivot = find_median_pivot(first, middle, last - 1); //Find the median of first, middle, last and sets it as the pivot
            std::iter_swap(pivot, last - 1);
            break;
    }
    pivot = partition(first, last - 1);

    quick_sort(first, pivot, method); //Partitions the left side of pivot point

    quick_sort(pivot + 1, last, method); //Partitions the right side of the pivot point
}
namespace alg {
    template<typename T>
    bool is_sorted(T first, T last) {
        for (; first != last - 1; first++) {
            if (*first > *(first + 1)) {
                std::cout << "Not sorted" << std::endl;
                return false;
            }
        }
        std::cout << "Sorted" << std::endl;
        return true;
    }
}

#endif
