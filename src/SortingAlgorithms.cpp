#include "SortingAlgorithms.h"
#include <algorithm>

// Helper function to compare products based on different criteria.
bool compareProducts(const Product& a, const Product& b, const std::string& criteria) {
    if (criteria == "price") return a.price < b.price;
    if (criteria == "rating") return a.rating < b.rating;
    return a.name < b.name; // Default to name comparison.
}

// Insertion Sort implementation.
void SortingAlgorithms::insertionSort(std::vector<Product>& products, const std::string& criteria) {
    for (size_t i = 1; i < products.size(); i++) {
        Product key = products[i];
        int j = i - 1;
        while (j >= 0 && compareProducts(key, products[j], criteria)) {
            products[j + 1] = products[j];
            j--;
        }
        products[j + 1] = key;
    }
}

// Selection Sort implementation.
void SortingAlgorithms::selectionSort(std::vector<Product>& products, const std::string& criteria) {
    for (size_t i = 0; i < products.size() - 1; i++) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < products.size(); j++) {
            if (compareProducts(products[j], products[minIndex], criteria)) {
                minIndex = j;
            }
        }
        std::swap(products[i], products[minIndex]);
    }
}

// Bubble Sort implementation.
void SortingAlgorithms::bubbleSort(std::vector<Product>& products, const std::string& criteria) {
    for (size_t i = 0; i < products.size() - 1; i++) {
        for (size_t j = 0; j < products.size() - i - 1; j++) {
            if (compareProducts(products[j + 1], products[j], criteria)) {
                std::swap(products[j], products[j + 1]);
            }
        }
    }
}

// Merge Sort implementation.
void merge(std::vector<Product>& products, int left, int mid, int right, const std::string& criteria) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<Product> L(n1), R(n2);
    
    for (int i = 0; i < n1; i++)
        L[i] = products[left + i];
    
    for (int j = 0; j < n2; j++)
        R[j] = products[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (compareProducts(L[i], R[j], criteria)) {
            products[k++] = L[i++];
        } else {
            products[k++] = R[j++];
        }
    }

    while (i < n1) 
        products[k++] = L[i++];

    while (j < n2) 
        products[k++] = R[j++];
}

void SortingAlgorithms::mergeSort(std::vector<Product>& products, const std::string& criteria) {
    for (int size = 1; size <= products.size() - 1; size *= 2) {
        for (int leftStart = 0; leftStart < products.size() - 1; leftStart += 2 * size) {
            int mid = std::min(leftStart + size - 1, static_cast<int>(products.size() - 1));
            int rightEnd = std::min(leftStart + 2 * size - 1, static_cast<int>(products.size() - 1));
            merge(products, leftStart, mid, rightEnd, criteria);
        }
    }
}

// Quick Sort implementation.
int partition(std::vector<Product>& products, int low, int high, const std::string& criteria) {
    Product pivot = products[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        if (compareProducts(products[j], pivot, criteria)) {
            i++;
            std::swap(products[i], products[j]);
        }
    }
    
    std::swap(products[i + 1], products[high]);
    
    return (i + 1);
}

void SortingAlgorithms::quickSort(std::vector<Product>& products, const std::string& criteria) {
    if (!products.empty()) 
        quickSortHelper(products, 0, static_cast<int>(products.size()) - 1, criteria);
}

void quickSortHelper(std::vector<Product>& products, int low, int high, const std::string& criteria) {
    if (low < high) {
        int pi = partition(products, low, high, criteria);
        
        quickSortHelper(products, low, pi - 1, criteria);
        quickSortHelper(products, pi + 1, high, criteria);
    }
}
