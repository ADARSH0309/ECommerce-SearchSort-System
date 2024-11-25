#ifndef PRODUCT_H
#define PRODUCT_H

#include <string>

class Product {
public:
    int id;
    std::string name;
    std::string category;
    float price;
    float rating;

    Product(int id, std::string name, std::string category, float price, float rating) 
        : id(id), name(name), category(category), price(price), rating(rating) {}
};

#endif // PRODUCT_H
