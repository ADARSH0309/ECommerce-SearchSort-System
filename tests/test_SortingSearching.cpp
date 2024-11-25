#include <iostream>
#include "../src/Product.h"
#include "../src/SortingAlgorithms.h"
#include "../src/SearchingAlgorithms.h"

void testSortingAndSearching() {

   // Create sample product list.
   std::vector<Product> productList;
   productList.push_back(Product(101,"Apple","Fruit",50.0f ,4.5f));
   productList.push_back(Product(102,"Banana","Fruit",30.0f ,4.7f));
   productList.push_back(Product(103,"Cherry","Fruit",20.0f ,4.3f));

   // Test Insertion Sort by Price.
   SortingAlgorithms::insertionSort(productList,"price");
   assert(productList[0].name == "Cherry"); // Check first element after sorting.

   // Test Binary Search by ID.
   Product* resultById = SearchingAlgorithms::binarySearch(productList ,101);
   assert(resultById != nullptr && resultById->id == 101); 
   delete resultById;

   // Test Quicksort by Rating.
   SortingAlgorithms::quickSort(productList,"rating");
   assert(productList[0].name == "Cherry"); 

   // Test Sequential Search by Name.
   Product* resultByName = SearchingAlgorithms::sequentialSearch(productList,"Apple");
   assert(resultByName != nullptr && resultByName->id == 101); 
   delete resultByName;

   std::cout << "All sorting and searching tests passed!" << std::endl;
}

int main() {
   testSortingAndSearching();
   return 0;
}
