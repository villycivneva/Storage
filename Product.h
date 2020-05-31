//
// Created by Velina on 02/05/2020.
//

#ifndef STORAGE_PRODUCT_H
#define STORAGE_PRODUCT_H

#include <iostream>
#include <cstring>
#include <cassert>

#include "Date.h"

enum Unit { Kilograms = 0, Liters = 1};

///This class **constructs a product**.
///
///It's a class that help us to make a products, store them in text file and read them from that file.
///
/// The variables(data members of the class) which are declared in Product are:
///
/// @arg char* **nameOfProduct** - this is the name of product, which has arbitrary length;
/// @arg Date **expirationDate** - the expiration date of the product;
/// @arg Date **dateOfEntryIntoStorage** - the date that the product enter into the storage;
/// @arg char* **nameOfMaker** - the name of the maker, who made the product and also has arbitrary length.
/// @arg Unit **units** - the unit of the product.
/// @arg size_t **currentQuantity** - current quantity of the product. It is size_t because it can't be negative number;
/// @arg int **locationOfProductInStorage**[3] - this is the location of the product. At location[0] -> which section, at location[1] -> which shelf and at location[2] -> which number.
/// @arg char* **comment** - the comment and it has arbitrary length.

class Product {
public:
    ///This is the **default** constructor.
    ///
    ///Default constructor is the constructor which doesn’t take any argument. It has no parameters.
    ///
    /// *The default values are:*
    /// @arg *nameOfProduct* - **N/A**
    /// @arg *expirationDate* - takes it from default constructor of class Date (2020-01-01).
    /// @arg *dateOfEntryIntoStorage* - takes it from default constructor of class Date (2020-01-01);
    /// @arg *nameOfMaker* - **N/A**
    /// @arg *units* - **Kilograms**
    /// @arg *currentQuantity* - **0**
    /// @arg *locationOfTheProduct* - [0]->0, [1]->0, [2]->0.
    /// @arg *comment* - **N/A**.
    Product();

    ///This is the constructor with parameters.
    ///
    ///It has 8 parameters:
    ///
    ///@param nameOfProduct -> this is the name of product, which has arbitrary length;
    ///@param expirationDate -> this is the expiration date of the product;
    ///@param dateOfEntryIntoStorage -> this is the date that the product enter into the storage;
    ///@param nameOfMaker -> the name of the maker, who made the product;
    ///@param units -> the unit of the product;
    ///@param currentQuantity -> current quantity of the product;
    ///@param locationOfProductInStorage -> this is the location of the product. At location[0] -> which section,
    ///at location[1] -> which shelf and at location[2] -> which number;
    ///@param comment -> a comment.
    ///@see Product() Product(const Product&)
    Product(const char*, const Date&, const Date&, const char*, Unit, size_t , const int* , const char*);

    ///This is copy constructor.
    ///
    ///With this constructor we make copies of the products.
    ///@see Product() Product(const char*, const Date&, const Date&, const char*, Unit, size_t , const int* , const char*)
    Product(const Product&);

    /// This is copy assignment operator.
    ///@note And assignment operator is called when an already initialized object is assigned a new value from another existing object.
    Product&operator=(const Product&);

    ///This is the **destructor**.
    ///
    /// When a class contains a pointer to memory allocated in class(as we have here for **nameOfProduct**, **nameOfMaker** and **comment**).
    ///
    /// We should write a destructor to release memory before the class instance is destroyed.
    ~Product();

    ///This is a mutator for the **nameOfProduct**.
    ///
    ///That function allow us to **change** the name of **nameOfProduct**.
    ///
    ///In the body of a function:
    ///
    ///@arg If we set empty name -> throw exception;
    ///@arg If we change the name of the product with correct name:
    ///
    ///     First we delete what we have in "nameOfProduct" and then we allocate memory for the new name + 1 (for '\0')
    ///     and we copy the value of newNameOfProduct to nameOfProduct;
    ///
    ///@param newNameOfProduct -> This is the new name of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setNameOfProduct(const char*);


    ///This is a mutator for the **expirationDate**.
    ///
    ///That function allow us to **change** the name of **expirationDate**.
    ///
    ///@param newExpirationDate -> This is the new expiration date of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setDateOfEntryIntoStorage(const Date&)
    void setExpirationDate(const Date&);


    ///This is a mutator for the **dateOfEntryIntoStorage**.
    ///
    ///That function allow us to **change** the name of **dateOfEntryIntoStorage**.
    ///
    ///@param newDateOfEntryIntoStorage -> This is the new expiration date of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setExpirationDate(const Date&)
    void setDateOfEntryIntoStorage(const Date&);


    ///This is a mutator for the **nameOfMaker**.
    ///
    ///That function allow us to **change** the name of a **nameOfMaker**.
    ///
    ///In the body of a function:
    ///
    ///@arg If we set empty name -> throw exception;
    ///
    ///@arg If we change the name of the maker with correct name:
    ///
    ///     First we delete what we have in "nameOfMaker" and then we allocate memory for the new name + 1 (for '\0')
    ///     and we copy the value of newNameOfMaker to nameOfMaker;
    ///
    ///@param newNameOfMaker -> This is the new name of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    ///@see setNameOfProduct(const char*)
    void setNameOfMaker(const char*);


    ///This is a mutator for the **units**.
    ///
    ///That function allow us to **change** the unit of **units**.
    ///
    ///@param newUnits -> This is the new unit of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setUnits(const Unit&);


    ///This is a mutator for the **currentQuantity**.
    ///
    ///That function allow us to **change** the quantity of **currentQuantity**.
    ///
    ///@param newCurrentQuantity -> This is the new current quantity of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setCurrentQuantity(size_t);

    ///This is a mutator for the **locationOfTheProductInStorage**.
    ///
    ///That function allow us to **change** the location of **locationOfTheProductInStorage**.
    ///
    ///@param newLocationOfTheProductInStorage -> This is the new location of the product in storage, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setLocationOfProductInStorage(const int*);


    ///This is a mutator for the **comment**.
    ///
    ///That function allow us to **change** the text in **comment**.
    ///
    ///In the body of a function:
    ///
    ///@arg If we set empty comment -> throw exception;
    ///
    ///@arg If we change the comment of product with correct one:
    ///
    ///     First we delete what we have in "comment" and then we allocate memory for the new comment + 1 (for '\0')
    ///     and we copy the value of newComment to comment;
    ///
    ///@param newComment This is the new name of the product, that we want to set.
    ///@returns The returns type is **void** , so we return: *Nothing*!
    void setComment(const char*);

    ///This is accessor for the **nameOfProduct**.
    ///
    /// @returns char* array filled with name of the product;
    /// @attention The accessor has **const** at the beginning of a function because the name of product that we return - doesn't change.
    /// @attention The function has **const** at the end because we don't change the current Product object.
    const char* getNameOfProduct() const;


    ///This is accessor for the **expirationDate**.
    ///
    /// @returns The expiration date of product.
    /// @attention The accessor has **const** at the end of a function because we don't change the current Product object.
    Date getExpirationDate() const;


    ///This is accessor for the **dateOfEntryIntoStorage**.
    ///
    ///@returns The date when the product entry into storage.
    /// @attention The accessor has **const** at the end of a function because we don't change the current Product object.
    Date getDateOfEntryIntoStorage() const;


    ///This is accessor for the **nameOfMaker**.
    ///
    /// @returns char* array filled with name of maker;
    /// @attention The accessor has **const** at the beginning of a function because the name of maker that we return - doesn't change.
    /// @attention The function has **const** at the end because we don't change the current Product object.
    const char* getNameOfMaker() const;


    ///This is accessor for the **units**.
    ///
    ///@returns Unit, which is *enum* variable: It can be : **Kilograms** or **Liters**;
    ///@attention The accessor has **const** at the end of a function because the current Product object that we return - don't change.
    Unit getUnit() const;


    ///This is accessor for the **currentQuantity**.
    ///
    ///@returns The current quantity of the product;
    ///@attention The accessor has **const** at the end of a function because the current Product object that we return - don't change.
    size_t getCurrentQuantity() const;


    ///This is accessor for the **locationOfTheProductInStorage**.
    ///
    /// @returns The location of the product in storage.
    /// @arg location[0] -> the section, where the product is.
    /// @arg location[1] -> the shelf in section, where the product is.
    /// @arg location[2] -> the number in shelf, where the product is.
    /// @attention The accessor has **const** at the beginning of a function because the location of the product that we return - doesn't change.
    /// @attention The accessor has **const** at the end of a function because the current Product object that we return - don't change.
    const int* getLocationOfProductInStorage() const;


    ///This is accessor for the **comment**.
    ///
    /// @returns char* array filled with the comment of product;
    /// @attention The accessor has **const** at the beginning of a function because the comment of the product that we return - doesn't change.
    /// @attention The accessor has **const** at the end of a function because the current Product object that we return - don't change.
    const char* getComment() const;



    ///The stream insertion operator “<<” is used for output.
    ///
    ///@returns The overloaded operator << returns a reference to the original *ostream* object.
    ///@warning It is important to make operator overloading function a friend of the class because it would be called without creating an object.
    friend std::ostream&operator<<(std::ostream& out, const Product& product);



    ///In this function we store the information about the products in file : **products.txt**.
    void storeInTextFile(std::ofstream&);

    ///In this function we read the information about the products from the file **products.txt**.
    void readFromTextFile(std::ifstream&);

    /// This function prints all the information about the products.
    ///
    ///@attention The function print() const has **const** at the end of a function because the things that we return - don't change.
    void print() const;

    /// This function prints partial information about the product.
    ///
    ///@param quantity -> we use prettyPrint() const when we want to know the quantity of some product;
    ///@attention The function prettyPrint() const has **const** at the end of a function because the things that we return - don't change.
    void prettyPrint(const int&) const;

private:
    char* nameOfProduct;
    Date expirationDate;
    Date dateOfEntryIntoStorage;
    char* nameOfMaker;
    Unit units;
    size_t currentQuantity;
    int locationOfProductInStorage[3];
    char* comment;
};





#endif //STORAGE_PRODUCT_H
