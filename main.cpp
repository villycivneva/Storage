#include <iostream>
#include "Date.h"
#include "Product.h"
#include <fstream>
#include <cstring>

#include "Storage.h"

int main() {

    Storage st;

    std::string command, fileName;
    std::ifstream file;

    bool isTheFileOpened = true;
    bool isTheFileClosed = false;


    std::cout<<"command: > ";
    getline(std::cin, command);

    while (command != "exit") {
        if (command.find("open", 0) != std::string::npos) {
            fileName = command.substr(5, command.size() - 5);
            file.open(fileName.c_str(), std::ios::in);
            if (!file.is_open()) {
                isTheFileOpened = false;
                std::cout << "The file can not be opened!" << std::endl;
                std::ifstream("systemFile.txt", std::ios::trunc | std::ios::app | std::ios::in);
                fileName = "systemFile.txt";
                std::cout << "You are working with systemFile.txt!" << std::endl;
            } else {
                /// while се върти докато не срещне еоf(край на файла);
                while (file.peek() != std::ifstream::traits_type::eof()) {
                    Product product;
                    product.readFromTextFile(file);
                    st.addProductHelper(product);
                }
                std::cout << "Successfully opened " << fileName << "!" << std::endl;
            }
        }

        if (command.find("close", 0) != std::string::npos && isTheFileOpened) {
            file.close();
            isTheFileClosed = true;
            std::cout << "Successfully closed " << fileName << "!" << std::endl;
        }

        if (command.find("save", 0) != std::string::npos && command.size() == 4 && isTheFileOpened &&
            !isTheFileClosed) {
            file.close();

            std::ofstream outputFile(fileName, std::ios::trunc | std::ios::app);

            if (!outputFile.is_open()) {
                std::cout << "The file is not opened!" << std::endl;
            } else {
                for (int i = 0; i < st.getSize(); i++) {
                    st.getProducts()[i].storeInTextFile(outputFile);
                    std::cout << i << ' ';
                }
                std::cout << "Successfully saved " << fileName << "!" << std::endl;
            }
            outputFile.close();
        }
        if (command.find("saveas", 0) != std::string::npos && isTheFileOpened && !isTheFileClosed) {
            std::cout << "Enter the new file name:";
            std::string newFileName;

            getline(std::cin, newFileName);
            std::cout << newFileName << std::endl;

            std::ofstream outputFile(newFileName.c_str(), std::ios::out | std::ios::trunc | std::ios::app);
            if (!outputFile.is_open()) {
                std::cout << "The file is not opened!" << std::endl;
            } else {
                for (int i = 0; i < st.getSize(); i++) {
                    st.getProducts()[i].storeInTextFile(outputFile);
                    std::cout << i << ' ';
                }
                std::cout << "Successfully saved as" << newFileName << "!" << std::endl;
                outputFile.close();
            }
        }
        if (command.find("help", 0) != std::string::npos) {
            std::cout << "The following commands are supported:" << std::endl;
            std::cout << "open <file>    opens <file>" << std::endl;
            std::cout << "close	       closes currently opened file" << std::endl;
            std::cout << "save	       saves the currently open file" << std::endl;
            std::cout << "saveas <file>  saves the currently open file in <file>" << std::endl;
            std::cout << "help	       prints this information" << std::endl;
            std::cout << "exit	       exists the program" << std::endl;
        }

        if (command.find("print", 0) != std::string::npos) {
            st.print();
        }
        if (command.find("add", 0) != std::string::npos) {
            st.addProduct();
        }
        if (command.find("remove", 0) != std::string::npos) {
            st.removeProduct();
        }
        if (command.find("log", 0) != std::string::npos) {
            std::string _firstDate = command.substr(4, 10);
            std::string _secondDate = command.substr(15, 10);

            Date firstDate(stoi(_firstDate.substr(0, 4)), stoi(_firstDate.substr(5, 2)), stoi(_firstDate.substr(8, 2)));
            Date secondDate(stoi(_secondDate.substr(0, 4)), stoi(_secondDate.substr(5, 2)),
                            stoi(_secondDate.substr(8, 2)));
            st.logProducts(firstDate, secondDate);
        }
        if (command.find("clean", 0) != std::string::npos) {
            st.cleanProduct();
        }
        std::cout<<"command: > ";
        getline(std::cin, command);
    }
    return 0;
}
