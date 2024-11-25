#ifndef SORTINGALGORITHMS_H
#define SORTINGALGORITHMS_H

#include <vector>
#include "Product.h"

class SortingAlgorithms {
public:
    static void insertionSort(std::vector<Product>& products, const std::string& criteria);
    static void selectionSort(std::vector<Product>& products, const std::string& criteria);
    static void bubbleSort(std::vector<Product>& products, const std::string& criteria);
    static void mergeSort(std::vector<Product>& products, const std::string& criteria);
    static void quickSort(std::vector<Product>& products, const std::string& criteria);
    static void heapSort(std::vector<Product>& products, const std::string& criteria);
};

#endif // SORTINGALGORITHMS_H
