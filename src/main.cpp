#include <iostream>
#include <vector>
#include "Product.h"
#include "SortingAlgorithms.h"
#include "SearchingAlgorithms.h"

int main() {
    
     // Sample product list creation.
     std::vector<Product> productList;
     productList.push_back(Product(101,"ProductA","CategoryX",50.0f,4.5f));
     productList.push_back(Product(102,"ProductB","CategoryY",30.0f,4.7f));
     productList.push_back(Product(103,"ProductC","CategoryX",20.0f,4.3f));

     // Insertion Sort by Price.
     SortingAlgorithms::insertionSort(productList,"price");
     std::cout << "Sorted by Price: \n";
     for(const auto &product : productList)
         std::cout << product.name << " - $" << product.price << "\n";

     // Binary Search by ID.
     Product* foundProductID = SearchingAlgorithms::binarySearch(productList ,101);
     if(foundProductID)
         std::cout << "Found by ID: {ID: " << foundProductID->id << ", Name: \"" << foundProductID->name << "\", Price: $" << foundProductID->price << "}\n";
     delete foundProductID;

     // Quicksort by Rating.
     SortingAlgorithms::quickSort(productList,"rating");
     std::cout << "Sorted by Rating: \n";
     for(const auto &product : productList)
         std::cout << product.name << " - Rating: " << product.rating << "\n";

     // Sequential Search by Name.
     Product* foundProductName = SearchingAlgorithms::sequentialSearch(productList,"ProductA");
     if(foundProductName)
         std::cout << "Found by Name: {ID: " << foundProductName->id << ", Name: \"" << foundProductName->name << "\", Price: $" << foundProductName->price << "}\n";
     delete foundProductName;

     return 0;
}
