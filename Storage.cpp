//
// Created by Velina on 15/05/2020.
//

#include "Storage.h"
#include <cmath>


Storage::Storage(size_t section, size_t shelf, size_t number) {
    setSection(section);
    setShelf(shelf);
    setNumber(number);
}


void Storage::setSection(size_t newSection) {
    this->section = newSection;
}

void Storage::setShelf(size_t newShelf) {
    this->shelf = newShelf;
}

void Storage::setNumber(size_t newNumber) {
    this->number = newNumber;
}

size_t Storage::getSection() const {
    return this->section;
}

size_t Storage::getShelf() const {
    return this->shelf;
}

size_t Storage::getNumber() const {
    return this->number;
}

Product * Storage::getProducts() const {
    return (Product*)this->products;
}


void Storage::print() const {
    int quantity = 0;
    bool* isCounted = new bool[size];

    //the total quantity of the products of the same name,
    // regardless of their expiration date.
    for (int i = 0; i < size; i++) {
        if (!isCounted[i]) {
            isCounted[i] = true;
            quantity += products[i].getCurrentQuantity();
            for (int j = i + 1; j < size; j++) {
                if (strcmp(products[i].getNameOfProduct(), products[j].getNameOfProduct()) == 0 && !isCounted[j]) {
                    quantity += this->products[j].getCurrentQuantity();
                    isCounted[j] = true;
                }
            }
            products[i].prettyPrint(quantity);
            quantity = 0;
        }
    }
}



void Storage::addProduct() {
    // If we don't have space for another product
    if (size + 1 > capacityOfStorage) {
        std::cout << "The storage is full" << std::endl;
        exit(1);
    }

    // construct the product, which we want to add into the storage
    Product product;

    //dialog mode
    std::cout<<"Enter the name of product:";
    char tmpName[255];
    std::cin.getline(tmpName, 255, '\n');
    product.setNameOfProduct(tmpName);

    int d, m, y;
    std::cout<<"Enter the expiration date: (day month year): ";
    std::cin >> d >> m >> y;
    Date expirationDate(y, m, d);
    product.setExpirationDate(expirationDate);


    std::cout<<"Enter the date when the product entry into the storage: (day month year): ";
    std::cin >> d >> m >> y;
    Date date2(y, m, d);
    product.setDateOfEntryIntoStorage(date2);

    std::cout<<"Enter the name of maker:";
    char tmpMaker[255];
    std::cin.get();
    std::cin.getline(tmpMaker, 255, '\n');
    product.setNameOfMaker(tmpMaker);


    std::cout << "0: Kilograms, 1: Liters" << std::endl;
    int unit;
    std::cin >> unit;
    unit ? product.setUnits(Unit::Liters) : product.setUnits(Unit::Kilograms);

    std::cout<<"Enter the quantity of product:";
    int quantity;
    std::cin >> quantity;
    product.setCurrentQuantity(quantity);


    int index = 0;
    for (int i = 0; i < getSize(); i++) {
        //if a new product has a different expiration date than an existing product
        // with the same name, it must be placed in a different place
        if (strcmp(tmpName, products[i].getNameOfProduct()) == 0) {
            if (expirationDate != products[i].getExpirationDate()) {
                // where we want to put it;
                std::cout << "Enter location different from:" << std::endl;
                for (int j = 0; j < 3; j++) {
                    std::cout << products[i].getLocationOfProductInStorage()[j] << ' ';
                }
                std::cout << std::endl;
            }

            // If we have enough space - the same products
            // with the same expiration date should be placed in the same place.
            if (size + 1 <= capacityOfStorage && (expirationDate == products[i].getExpirationDate())) {
                product.setCurrentQuantity(products[i].getCurrentQuantity() + product.getCurrentQuantity());
                product.setLocationOfProductInStorage(products[i].getLocationOfProductInStorage());
            }
        } else {
            std::cout << "Enter location different from:" << std::endl;
            for (int j = 0; j < 3; j++) {
                std::cout << products[i].getLocationOfProductInStorage()[j] << ' ';
            }
            std::cout << std::endl;
        }
    }

    int arr[3];
    std::cin >> arr[0] >> arr[1] >> arr[2];
    product.setLocationOfProductInStorage(arr);
    index = (arr[0] - 1) * 100 + (arr[1] - 1) * 10 + (arr[2] - 1);
    if(!spaceInStorage[index]) {
        spaceInStorage[index] = true;
    }

    std::cout<<"Enter the comment:";
    char tmpComment[255];
    std::cin.get();
    std::cin.getline(tmpComment, 255, '\n');
    product.setComment(tmpComment);

    //If we have space for another product
    if (size + 1 <= capacityOfStorage) {
        products[size++] = product;
        std::cout<<"Successfully added!"<<std::endl;
    }
}

void Storage::addProductHelper(const Product& product) {
    if (size + 1 <= capacityOfStorage) {
        products[size++] = product;
        if (size == capacityOfStorage) {
            std::cout << "The storage is full!" << std::endl;
            exit(1);
        }
    }
}


void Storage::removeProduct() {
    if(size <= 0){
        return;
    }
    std::cout << "Enter the name of the product which you want to be removed: ";
    char name[255];
    std::cin.getline(name, 255, '\n');

    std::cout << "Enter the quantity that you want to remove: ";
    int quantity;
    std::cin >> quantity;

    int totalQuantity = 0;

    for (int i = 0; i < size; i++) {
        if (strcmp(name, this->products[i].getNameOfProduct()) == 0) {
            totalQuantity += this->products[i].getCurrentQuantity();
        }
    }
    if (totalQuantity < quantity) {
        std::cout << "You have " << totalQuantity << " of this product. Are you sure you want to remove everything?"
                  << std::endl;
        std::cout << "Choose YES or NO:";
        char answer[4];
        std::cin.get();
        std::cin.getline(answer, 4, '\n');


        if (strcmp("NO", answer) == 0)
            return;
        else {
            removeHelper(name,quantity);
        }
    } else {
        bool *array = new bool[capacityOfStorage];

        Date currentMin = products[0].getExpirationDate();
        for (int i = 0; i < quantity; i++) {
            int position = 0;
            for (int j = i + 1; j < getSize(); j++) {
                if (this->products[j].getExpirationDate() < currentMin &&
                    strcmp(name, products[j].getNameOfProduct()) == 0 && !array[j]) {
                    currentMin = this->products[j].getExpirationDate();
                    position = j;
                }
                array[position] = true;
            }
        }
        removeHelper(name,quantity);
    }
}

void Storage::removeHelper(const char* name, int quantity) {
    Product newProducts[MAX*MAX*MAX];

    int index = 0;
    int indexOfSpace = 0;
    for (int i = 0; i < getSize(); i++) {
        if (strcmp(name, this->products[i].getNameOfProduct()) != 0) {
            newProducts[index++] = this->products[i];
        } else {
            indexOfSpace = (products[i].getLocationOfProductInStorage()[0] - 1) * 100
                           + (products[i].getLocationOfProductInStorage()[1] - 1) * 10
                           + (products[i].getLocationOfProductInStorage()[2] - 1);
            std::cout << "Position of the product was: ";
            for (int k = 0; k < 3; k++) {
                std::cout << products[i].getLocationOfProductInStorage()[k] << ' ';
            }

            if (products[i].getCurrentQuantity() <= quantity) {
                spaceInStorage[indexOfSpace] = false;
            } else{
                products[i].setCurrentQuantity(products[i].getCurrentQuantity() - quantity);
                newProducts[index++] = products[i];
            }
        }
    }
    setSize(index);
    for(int i = 0 ; i < index; i++) {
        products[i] = newProducts[i];
    }
    std::cout<<"Successfully removed!"<<std::endl;
}


void Storage::logProducts(const Date& firstDate, const Date& secondDate) const {
    bool hasResult = false;

    for(int i = 0; i < size; i++){
        if(products[i].getDateOfEntryIntoStorage() >= firstDate && products[i].getDateOfEntryIntoStorage() <= secondDate){
            hasResult = true;
            std::cout<<"On "<<products[i].getDateOfEntryIntoStorage()<<" was added: "<<std::endl;
            // quantity is -1 because we don't have to know the quantity here.
            products[i].prettyPrint(-1);
        }
    }
    if(!hasResult){
        std::cout<<"No changes in storage!" << std::endl;
    }
}


void Storage::cleanProduct() {
    int day,month,year;
    std::cout<<"Please, enter today's date (day month year): ";
    std::cin>>day>>month>>year;

    Date date(year,month,day);

    int _size = this->getSize();

    //We clear the storage of all products that have expired or are about to expire.
    for(int i = 0; i < _size ;i++){
        if(date.isExpiringSoon(products[i].getExpirationDate()) || products[i].getExpirationDate() < date){
            removeHelper(products[i].getNameOfProduct(),products[i].getCurrentQuantity());
        }
    }
}



















































































