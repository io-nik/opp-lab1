//
// Created by ionik on 07.09.2024.
//

#include <iostream>
#include <limits>
#include "input.h"
#include "Part.h"


unsigned int input::getUnsgnInt() { // отр?
    long int x = 0;
    bool flag = false;
    while(!flag) {
        std::cin >> x;

        if (std::cin.eof()) {
            throw std::runtime_error("getUnsgnInt: EOF");
        }
        if (std::cin.bad()) {
            throw std::runtime_error("getUnsgnInt: Bad Input");
        }
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        if(x < 0)
            flag = false;
        else
            flag = true;
    }
    return static_cast<unsigned int>(x);
}


std::string input::getString() {
    using namespace std;

    string str;
    bool flag = false;
    while(!flag) {
        std::getline(cin, str); //не даёт идти дальше, пока не ввести ненужную строку

        if(cin.eof()) {
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw std::runtime_error("getString: EOF");
        }
        else if(cin.fail()) { // if stream extraction failed
            cout << "Incorrect Input" << endl;
            cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
            flag = true;
    }
    return str;
}


unsigned int input::getCount() {
    return input::getUnsgnInt();
}


std::string input::getId() {
    std::cin.clear();
    std::string _id = input::getString();
    while(_id.find(':') != std::string::npos or _id.find('\"') != std::string::npos or _id.length() != 8) {
        _id = input::getString();
    }
    return _id;
}


std::string input::getName() {
    std::cin.clear();
    std::string _name = input::getString();
    while(_name.empty())
        _name = input::getString();

    return _name;
}


Part input::inputStruct() {
    Part p;
    std::cout << "Input id (8 symb)" << std::endl;
    p.id = input::getId();
    std::cout << "Input name" << std::endl;
    p.name = input::getName();
    std::cout << "Input count" << std::endl;
    p.count = input::getCount();

    return p;
}


std::string input::inputString() {
    return input::getString();
} // {"id":"qwerasdf","name":"det","count":5}