//
// Created by samuel on 3/29/22.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>

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

enum pivot {MEDIAN_OF_THREE, RIGHT_ELEMENT};

template<typename T>
void quick_sort(T first, T last, pivot method) {
    if(first != last) {
        T pivot = partition(first, last - 1, method);

        quick_sort(first, pivot, method); //Partitions the left side of pivot point

        quick_sort(pivot + 1, last, method); //Partitions the right side of the pivot point
    }
}

template<typename T>
T find_median_pivot(T first, T middle, T last) {
    if((*first > *middle) ^ (*first > *last)) {
        return first;
    }
    else if((*middle < *first) ^ (*middle < *last)) {
        return middle;
    }
    else
        return last;
}

template<typename T>
T partition(T first, T last, pivot method) {
    T pivot;
    if(method == MEDIAN_OF_THREE) {
        ptrdiff_t half = (last + 1 - first) / 2;
        T middle = first + half;
        pivot = find_median_pivot(first, middle, last);
    }
    if(method == RIGHT_ELEMENT)
        pivot = last; //right side pivot

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


/*
 * ptrdiff_t half = (end - begin) / 2;
 * middle = begin + half;
 */

#endif
