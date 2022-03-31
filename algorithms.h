//
// Created by samuel on 3/29/22.
//

#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <algorithm>
#include <iostream>

enum pivot {MEDIAN_OF_THREE, RIGHT_ELEMENT};

template<typename T>
struct find_median {
public:
    find_median(T first, T middle, T last): m_first(first), m_middle(middle), m_last(last), finished(false) {}

    operator T() {
        return m_middle;
    }

    bool compare(T e1, T e2, T e3) { //Comparing element 1, 2, 3
        if((*e1 < *e2 && *e2 < *e3) || (*e3 < *e2 && *e2 < *e1)) {
            if(*e1 > *e3) {
                std::iter_swap(e1, e3);
            }
            finished = true;
            return true;
        }
        return false;
    }

    find_median& first() {
        if(!finished) {
            if(compare(m_middle, m_first, m_last)) {
                std::iter_swap(m_first, m_middle);
            }
        }
        return *this;
    }

    find_median& middle() {
        if(!finished) {
            compare(m_first, m_middle, m_last);
        }
        return *this;
    }

    find_median& last() {
        if(!finished) {
            if(compare(m_first, m_last, m_middle)) {
                std::iter_swap(m_middle, m_last);
            }
        }
        return *this;
    }

private:
    T m_first, m_middle, m_last;
    bool finished;
};

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
    find_median<T> comparer(first, middle, last);
    return comparer.first().middle().last();
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
    void sort(T first, T last) {
        std::sort(first, last);
    }

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
