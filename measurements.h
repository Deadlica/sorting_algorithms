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

enum algorithm {SELECTION_SORT, INSERTION_SORT, R_QUICK_SORT, MO3_QUICK_SORT, STD_SORT};
enum sorted {RANDOM, SORTED, REVERSE_SORTED, CONSTANT};

template<typename T>
class measurements {
public:
    measurements(size_t N): samples(N), size({20000, 40000, 60000, 80000, 100000, 120000, 140000, 160000, 180000, 200000}) {}


    void operator()(algorithm method, sorted container) {
        for(auto e: size) {
            switch (container) {
                case RANDOM:
                    generateRandom(e);
                    break;
                case SORTED:
                    generateOrder(size.front(), RISING);
                    break;
                case REVERSE_SORTED:
                    generateOrder(size.front(), FALLING);
                    break;
                case CONSTANT:
                    generateConstant(size.front());
                    break;
            }
        }
    }

    const double std_dev(std::vector<double> measurements) {
        const int N = measurements.size();
        double sum = std::accumulate(measurements.begin(),measurements.end(), 0);
    }

private:
    Timer timer;
    size_t samples;
    std::vector<int> size;
    std::vector<double> m_measurements;

    void reset() {
        size.clear();
        m_measurements.clear();
    }
};


#endif
