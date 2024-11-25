#include "SearchingAlgorithms.h"

// Sequential Search implementation.
Product* SearchingAlgorithms::sequentialSearch(const std::vector<Product>& products, const std::string& name) {
    for (const auto& product : products) {
        if (product.name == name)
            return new Product(product); // Return a copy of the found product.
    }
    return nullptr; // Not found.
}

// Binary Search implementation.
Product* SearchingAlgorithms::binarySearch(const std::vector<Product>& sortedProducts, int id) {
    int left = 0;
    int right = sortedProducts.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (sortedProducts[mid].id == id)
            return new Product(sortedProducts[mid]); // Return a copy of the found product.

        if (sortedProducts[mid].id < id)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return nullptr; // Not found.
}
