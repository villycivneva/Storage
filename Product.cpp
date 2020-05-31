//
// Created by Velina on 02/05/2020.
//

#include "Product.h"
#include <fstream>

Product::Product() {
    nameOfProduct  = "N/A";
    expirationDate = {2000,1,1};
    dateOfEntryIntoStorage = expirationDate = {2000,1,1};
    nameOfMaker = "N/A";
    units = Kilograms;
    currentQuantity = 0;
    for(int i = 0;i < 3;i ++){
        locationOfProductInStorage[i] = 0;
    }
    comment = "N/A";
}


Product::Product(const char* nameOfProduct, const Date& expirationDate, const Date& dateOfEntryIntoStorage, const char* nameOfMaker,
        Unit units, size_t currentQuantity, const int* locationOfProductInStorage, const char* comment) {
    setNameOfProduct(nameOfProduct);
    setExpirationDate(expirationDate);
    setDateOfEntryIntoStorage(dateOfEntryIntoStorage);
    setNameOfMaker(nameOfMaker);
    setUnits(units);
    setCurrentQuantity(currentQuantity);
    setLocationOfProductInStorage((const int*) locationOfProductInStorage);
    setComment(comment);
}

Product::Product(const Product & other) {
    setNameOfProduct(other.nameOfProduct);
    setExpirationDate(other.expirationDate);
    setDateOfEntryIntoStorage(other.dateOfEntryIntoStorage);
    setNameOfMaker(other.nameOfMaker);
    setUnits(other.units);
    setCurrentQuantity(other.currentQuantity);
    setLocationOfProductInStorage((const int*)(other.locationOfProductInStorage));
    setComment(other.comment);
}

Product & Product::operator=(const Product & other) {
    if(this != &other){
        setNameOfProduct(other.nameOfProduct);
        setExpirationDate(other.expirationDate);
        setDateOfEntryIntoStorage(other.dateOfEntryIntoStorage);
        setNameOfMaker(other.nameOfMaker);
        setUnits(other.units);
        setCurrentQuantity(other.currentQuantity);
        setLocationOfProductInStorage((const int*)(other.locationOfProductInStorage));
        setComment(other.comment);
    }
    return *this;
}

Product::~Product() {
    delete[] this->nameOfProduct;
    delete[] this->nameOfMaker;
    delete[] this->comment;
}

void Product::setNameOfProduct(const char * newNameOfProduct) {
    delete[] this->nameOfProduct;

    if(!newNameOfProduct) {
        strcpy(this->nameOfProduct, "N/A");
    }else {
        this->nameOfProduct = new char[strlen(newNameOfProduct) + 1];
        strcpy(this->nameOfProduct, newNameOfProduct);
    }
}

void Product::setExpirationDate(const Date& newExpirationDate) {
    this->expirationDate = newExpirationDate;
}

void Product::setDateOfEntryIntoStorage(const Date & newDateOfEntryIntoStorage) {
    this->dateOfEntryIntoStorage = newDateOfEntryIntoStorage;
}

void Product::setNameOfMaker(const char * newNameOfMaker) {
    delete[] this->nameOfMaker;

    if(!newNameOfMaker) {
        strcpy(this->nameOfMaker, "N/A");
    }else {
        this->nameOfMaker = new char[strlen(newNameOfMaker) + 1];
        strcpy(this->nameOfMaker, newNameOfMaker);
    }
}

void Product::setUnits(const Unit& newUnit) {
    this->units = newUnit;
}

void Product::setCurrentQuantity(size_t newCurrentQuantity) {
    this->currentQuantity = newCurrentQuantity;
}

void Product::setLocationOfProductInStorage(const int* newLocationOfProductInStorage) {
    if(newLocationOfProductInStorage == nullptr){
        std::cout<<"NO!";
        exit(1);
    }

    for(int i = 0; i < 3; i++){
        this->locationOfProductInStorage[i] = newLocationOfProductInStorage[i];
    }
}

void Product::setComment(const char * newComment) {
    delete[] this->comment;

    if(!newComment) {
        strcpy(this->comment, "N/A");
    }else {
        this->comment = new char[strlen(newComment) + 1];
        strcpy(this->comment, newComment);
    }
}



const char * Product::getNameOfProduct() const {
    return this->nameOfProduct;
}

Date Product::getExpirationDate() const {
    return this->expirationDate;
}

Date Product::getDateOfEntryIntoStorage() const {
    return this->dateOfEntryIntoStorage;
}

const char * Product::getNameOfMaker() const {
    return (char*)this->nameOfMaker;
}

Unit Product::getUnit() const {
    return this->units;
}

size_t Product::getCurrentQuantity() const {
    return this->currentQuantity;
}

const int* Product::getLocationOfProductInStorage() const {
    return this->locationOfProductInStorage;
}

const char* Product::getComment() const {
    return this->comment;
}

std::ostream &operator<<(std::ostream &out, const Product& product) {
    out << product.getNameOfProduct() << product.getExpirationDate() << product.getDateOfEntryIntoStorage() << product.getNameOfMaker() << product.getUnit()
        << product.getCurrentQuantity() << product.getLocationOfProductInStorage() << product.getComment();
    return out;
}


void Product::storeInTextFile(std::ofstream& outputFile) {
    outputFile << this->getNameOfProduct() << ',';
    outputFile << this->getExpirationDate()<< ',';
    outputFile << this->getDateOfEntryIntoStorage() << ',';
    outputFile << this->getNameOfMaker() << ',';
    outputFile << (this->getUnit() ? "Liters" : "Kilograms");
    outputFile << ',';
    outputFile << this->getCurrentQuantity() << ',';
    for(int i = 0; i < 3; i++) {
        outputFile << this->getLocationOfProductInStorage()[i] << ',';
    }
    outputFile << this->getComment() << '\n';
}



void Product::readFromTextFile(std::ifstream& inputFile) {

    // dialog mode
    char tmpName[255];
    inputFile.getline(tmpName, 255, ',');
    this->setNameOfProduct(tmpName);

    Date tmpExpirationDate;
    inputFile >> tmpExpirationDate;

    this->setExpirationDate(tmpExpirationDate);

    Date tmpDateOfEntryIntoStorage;
    inputFile >> tmpDateOfEntryIntoStorage;
    this->setDateOfEntryIntoStorage(tmpDateOfEntryIntoStorage);

    char tmpMaker[255];
    inputFile.getline(tmpMaker, 255, ',');
    this->setNameOfMaker(tmpMaker);


    char tmpUnit[10];
    inputFile.getline(tmpUnit, 10, ',');
    Unit _tmpUnit;
    (strcmp(tmpUnit, "Kilograms") == 0) ? _tmpUnit = Unit::Kilograms : _tmpUnit = Unit::Liters;
    this->setUnits(_tmpUnit);


    int curr;
    inputFile >> curr;
    this->setCurrentQuantity(curr);

    int arr[3];
    inputFile.get();
    for (int i = 0; i < 3; i++) {
        inputFile >> arr[i];
        inputFile.get();
    }
    this->setLocationOfProductInStorage(arr);

    char tmpComment[255];
    inputFile.getline(tmpComment, 255, '\n');
    this->setComment(tmpComment);


}


void Product::print() const {
    std::cout << "Name of product: " << getNameOfProduct()<<std::endl;
    std::cout << "Expiration date: " << getExpirationDate()<<std::endl;
    std::cout << "Date Of Entry Into Storage: " << getDateOfEntryIntoStorage() << std::endl;
    std::cout<<"Name of maker: "<<getNameOfMaker()<<std::endl;
    std::cout<<"Unit: " << (this->getUnit() ? "Liters" : "Kilograms");
    std::cout << std::endl;
    std::cout<<"Current Quantity: "<<getCurrentQuantity()<<std::endl;
    std::cout << "Location Of Product In Storage: ";
    for(int i = 0; i < 3; i++) {
        std::cout << getLocationOfProductInStorage()[i];
        if( i < 2){
            std::cout << ", ";
        }
    }
    std::cout<<std::endl;
    std::cout<<"Comment: "<<this->getComment()<<std::endl;
}



void Product::prettyPrint(const int& quantity) const {
    std::cout << "Name of product: " << getNameOfProduct() << std::endl;
    std::cout << "Expiration date: " << getExpirationDate() << std::endl;
    std::cout << "Name of maker: " << getNameOfMaker() << std::endl;
    std::cout << "Unit: " << (this->getUnit() ? "Liters" : "Kilograms");
    std::cout << std::endl;
    std::cout << "Location Of Product In Storage: ";
    for (int i = 0; i < 3; i++) {
        std::cout << getLocationOfProductInStorage()[i];
        if (i < 2) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
    if (quantity != -1) {
        std::cout << "Quantity: " << quantity << std::endl;
    }

}




