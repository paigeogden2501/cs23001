// File: object_construction.cpp

#include "object_construction.hpp"

Object::Object(){
    std::cout << "Called default ctor" << std::endl;
}

Object::~Object(){
    std::cout << "Called destructor, dtor" << std::endl;
}

Object::Object(const Object& copy){
    std::cout << "Called copy ctor" << std::endl;
}

Object Object::operator=(const Object& rhs){
    Object temp;
    std::cout << "Called assignment operator" << std::endl;
    return temp;
}
