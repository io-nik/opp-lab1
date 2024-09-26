//
// Created by ionik on 23.09.2024.
//
#include "Part.h"
#include <iostream>

Part create(std::string _id, std::string _name, unsigned int _count) {
    Part p;
    p.id = _id;
    p.name = _name;
    p.count = _count;

    return p;
};


bool compare(Part& p1, Part& p2) {
    if(p1.id == p2.id and p1.name == p2.name and p1.count == p2.count)
        return true;
    else
        return false;
}