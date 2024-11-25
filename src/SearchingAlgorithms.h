#ifndef SEARCHINGALGORITHMS_H
#define SEARCHINGALGORITHMS_H

#include <vector>
#include "Product.h"

class SearchingAlgorithms {
public:
    static Product* sequentialSearch(const std::vector<Product>& products, const std::string& name);
    static Product* binarySearch(const std::vector<Product>& sortedProducts, int id);
};

#endif // SEARCHINGALGORITHMS_H
