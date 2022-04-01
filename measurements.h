//
// Created by samuel on 3/31/22.
//

#ifndef MEASUREMENTS_H
#define MEASUREMENTS_H


#include <cstdlib>
#include <vector>
#include <numeric>
#include <fstream>
#include "algorithms.h"
#include "data_generation.h"
#include "timer.h"

enum algorithm {INSERTION_SORT, SELECTION_SORT, R_QUICK_SORT, MO3_QUICK_SORT, STD_SORT};
enum sorted {RANDOM, SORTED, REVERSE_SORTED, CONSTANT};

template<typename T>
class measurements {
public:
    measurements(size_t N): samples(N), size({(T)20000.1, (T)40000.1, (T)60000.1, (T)80000.1, (T)100000.1, (T)120000.1, (T)140000.1, (T)160000.1, (T)180000.1, (T)200000.1}) {}


    void operator()(algorithm algorithm, sorted container) {
        for(auto e: size) {
            m_measurements.clear();
            m_currentSize = e;
            for(int i = 0; i < samples; i++) {
                generate(container, e);
                measurements::sort(algorithm);
            }
            m_std_dev = std_dev();
            exportToFile(algorithm, container);
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

    void sort(algorithm algorithm) {
        switch(algorithm) {
            case INSERTION_SORT:
                timer.start();
                insertion_sort(list.begin(), list.end());
                timer.stop();
                break;
            case SELECTION_SORT:
                timer.start();
                selection_sort(list.begin(), list.end());
                timer.stop();
                break;
            case R_QUICK_SORT:
                timer.start();
                quick_sort(list.begin(), list.end(), RIGHT_ELEMENT);
                timer.stop();
                break;
            case MO3_QUICK_SORT:
                timer.start();
                quick_sort(list.begin(), list.end(), MEDIAN_OF_THREE);
                timer.stop();
                break;
            case STD_SORT:
                timer.start();
                std::sort(list.begin(), list.end());
                timer.stop();
                break;
        }
        m_measurements.push_back(timer.time());
    }

    double std_dev() {
        const int N = samples;
        double sum = std::accumulate(m_measurements.begin(), m_measurements.end(), 0.0);
        m_mean = sum / N;

        auto devSum = [this](double measurement) {return std::pow(measurement - m_mean, 2);};
        std::transform(m_measurements.begin(), m_measurements.end(), m_measurements.begin(), devSum);
        double squareSum = std::accumulate(m_measurements.begin(), m_measurements.end(), 0.0);

        return std::sqrt((1.0 / (N - 1.0)) * squareSum);
    }

    void exportToFile(algorithm algorithm, sorted container) {
        std::ofstream file(setTitle(algorithm, container) + ".txt", std::ios_base::app);
        if(file.is_open()) {
            file << (int)m_currentSize << "\t" << m_mean << "\t" << m_std_dev << "\t" << samples << std::endl;
            file.close();
        }
    }

private:
    Timer timer;
    size_t samples;
    double m_std_dev, m_mean, m_currentSize;
    std::vector<double> m_measurements;
    std::vector<T> size;
    std::vector<T> list;

    std::string setTitle(algorithm method, sorted container) {
        std::string title;
        switch(method) {
            case INSERTION_SORT:
                title = "Insertion sort";
                break;
            case SELECTION_SORT:
                title = "Selection sort";
                break;
            case R_QUICK_SORT:
                title = "Quick sort with right pivot";
                break;
            case MO3_QUICK_SORT:
                title = "Quick sort with median of three pivot";
                break;
            case STD_SORT:
                title = "std::sort";
                break;
        }
        switch(container) {
            case RANDOM:
                title += " (random)";
                break;
            case SORTED:
                title += " (sorted)";
                break;
            case REVERSE_SORTED:
                title += " (reverse sorted)";
                break;
            case CONSTANT:
                title += " (constant)";
                break;
        }
        return title;
    }

    void reset() {
        size.clear();
        m_measurements.clear();
    }
};

#endif
