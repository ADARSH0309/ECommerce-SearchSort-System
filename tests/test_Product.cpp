#include <iostream>
#include "../src/Product.h"

void testProductCreation() {
   Product p(101,"TestProduct","TestCategory",99.99f ,4.8f);
   assert(p.id == 101);
   assert(p.name == "TestProduct");
   assert(p.category == "TestCategory");
   assert(p.price == 99.99f);
   assert(p.rating == 4.8f);

   std::cout << "All Product tests passed!" << std::endl;
}

int main() {
   testProductCreation();
   return 0;
}
