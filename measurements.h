//
// Created by samuel on 3/31/22.
//

#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H


#include <cstdlib>
#include <vector>
#include <numeric>
#include "algorithms.h"
#include "data_generation.h"
#include "timer.h"

enum algorithm {INSERTION_SORT, SELECTION_SORT, R_QUICK_SORT, MO3_QUICK_SORT, STD_SORT};
enum sorted {RANDOM, SORTED, REVERSE_SORTED, CONSTANT};

template<typename T>
class measurements {
public:
    measurements(size_t N): samples(N), size({(T)20000.1, (T)40000.1, (T)60000.1, (T)80000.1, (T)100000.1, (T)120000.1, (T)140000.1, (T)160000.1, (T)180000.1, (T)200000.1}) {}


    void operator()(algorithm method, sorted container) {
        for(auto e: size) {
            m_measurements.clear();
            for(int i = 0; i < samples; i++) {
                generate(container, e);
                measurements::sort(method);
                std_dev(m_measurements);
                alg::is_sorted(list.begin(), list.end());
                std::cout << m_measurements.back() << std::endl;
            }
        }
    }

    void generate(sorted container, T size) {
        switch (container) {
            case RANDOM:
                list = generateRandom(size);
                break;
            case SORTED:
                list = generateOrder(size, RISING);
                break;
            case REVERSE_SORTED:
                list = generateOrder(size, FALLING);
                break;
            case CONSTANT:
                list = generateConstant(size);
                break;
        }
    }

    void sort(algorithm method) {
        switch(method) {
            case INSERTION_SORT:
                timer.start();
                insertion_sort(list.begin(), list.end());
                timer.stop();
                m_measurements.push_back(timer.time());
                break;
            case SELECTION_SORT:
                timer.start();
                selection_sort(list.begin(), list.end());
                timer.stop();
                m_measurements.push_back(timer.time());
                break;
            case R_QUICK_SORT:
                timer.start();
                quick_sort(list.begin(), list.end(), RIGHT_ELEMENT);
                timer.stop();
                m_measurements.push_back(timer.time());
                break;
            case MO3_QUICK_SORT:
                timer.start();
                quick_sort(list.begin(), list.end(), MEDIAN_OF_THREE);
                timer.stop();
                m_measurements.push_back(timer.time());
                break;
            case STD_SORT:
                timer.start();
                std::sort(list.begin(), list.end());
                timer.stop();
                m_measurements.push_back(timer.time());
                break;
        }
    }

    const double std_dev(std::vector<double> measurements) {
        const int N = measurements.size();
        double sum = std::accumulate(measurements.begin(),measurements.end(), 0);
    }

private:
    Timer timer;
    size_t samples;
    std::vector<double> m_measurements;
    std::vector<T> size;
    std::vector<T> list;

    void reset() {
        size.clear();
        m_measurements.clear();
    }
};


#endif
