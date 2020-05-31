//
// Created by Velina on 15/05/2020.
//

#ifndef STORAGE_STORAGE_H
#define STORAGE_STORAGE_H


#include <cstddef>
#include <cmath>
#include "Product.h"

const size_t MAX = 10;
const int capacityOfStorage = pow(MAX,3);

///This class **constructs a storage**.
///
///It's a class that help us to store the products in one place. We can *add*, *remove* and *clean* products.
///
/// The variables(data members of the class) which are declared in Storage are:
///
/// @arg size_t **section** - this is the section, where products are located.
/// @arg size_t **shelf** - this is the shelf, where products are located in section.
/// @arg size_t **number** - this is the number, where products are located in shelf.
/// @arg Product **products** - a lot of products from  Product (static array with size 1000).
/// @arg int **size** - the number of products;
///
/// We have one private function:
///@arg void removeHelper().
class Storage {
public:

    ///This is the default constructor and constructor with parameters in one place.
    ///
    ///It has 3 parameters, which construct a storage:
    ///
    ///@param section -> this is the sections, where the product is.
    ///@param shelf -> this is the shelf in section, where the product is.
    ///@param number -> this is the number in shelf, where the product is.
    Storage(size_t = 5,size_t = 5,size_t = 10);



    ///This is a mutator for the **section**.
    ///
    ///That function allow us to **change** the **section** where product is located.
    ///
    ///@param newSection -> This is the new section where product is located.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setShelf(size_t) setNumber(size_t)
    void setSection(size_t);


    ///This is a mutator for the **shelf**.
    ///
    ///That function allow us to **change** the **shelf** in section where product is located.
    ///
    ///@param newShelf -> This is the new shelf where product is located.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setSection(size_t) setNumber(size_t)
    void setShelf(size_t);


    ///This is a mutator for the **number**.
    ///
    ///That function allow us to **change** the **number** in shelf where product is located.
    ///
    ///@param newNumber -> This is the new number where product is located.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setShelf(size_t) setSection(size_t)
    void setNumber(size_t);



    ///This is accessor for **section** in storage.
    ///
    ///@returns location of the product in section
    ///@attention The accessor has **const** at the end of a function because the current Storage object that we return - doesn't change.
    size_t getSection() const;


    ///This is accessor for **shelf** in section in storage.
    ///
    ///@returns location of the product in shelf
    ///@attention The accessor has **const** at the end of a function because the current Storage object that we return - doesn't change.
    size_t getShelf() const;


    ///This is accessor for **number** in shelf in storage.
    ///
    ///@returns the number in shelf where product is located
    ///@attention The accessor has **const** at the end of a function because the current Storage object that we return - doesn't change.
    size_t getNumber() const;



    ///This is accessor for **size**.
    ///
    ///@returns the size of products array.
    ///@attention The accessor has **const** at the end of a function because the current Storage object that we return - doesn't change.
    int getSize() const { return this->size;}


    ///This is accessor for **products** in storage.
    ///
    ///@returns the products in storage;
    ///@attention The accessor has **const** at the end of a function because the current Storage object that we return - doesn't change.
    Product* getProducts() const;





    ///This function adds a product into the storage;
    ///
    ///@note More details about the function, You may see the comments in code :)
    void addProduct();


    ///This is helper for addProduct() function;
    ///
    ///@note I made that function for easy testing the function!
    void addProductHelper(const Product&);



    ///This function removes a product from the storage;
    ///
    ///@note More details about the function, You may see the comments in code :)
    void removeProduct();


    ///In this function - we are clearing the storage of all foods that have expired or are about to have invalid expiration date.
    void cleanProduct();



    ///Displays all changes in availability in the period from first date to second date, which are arguments in the function;
    ///
    ///@param firstDate -> this is the first date "from" where we want to display all the changes in store.
    ///@param secondDate -> this is the second date "to" where we want to display all the changes in store.
    ///@attention The function has **const** at the end because we don't change anything.
    void logProducts(const Date&, const Date&) const;

    ///That function prints all the information about the storage.
    ///
    ///@attention The function has **const** at the end because we don't change anything, we just prints the information.
    void print() const;

    ///This is a mutator for the **size**.
    ///
    ///That function allow us to **change** the **size**.
    ///
    ///@param newSize -> This is the new size.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setSize(int newSize){ this->size = newSize;}

private:
    size_t section;
    size_t shelf;
    size_t number;

    Product products[MAX * MAX * MAX];

    bool spaceInStorage[MAX * MAX * MAX]{false};

    int size{0};

    void removeHelper(const char*,int);
};


#endif //STORAGE_STORAGE_H
