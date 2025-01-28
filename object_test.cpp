// File: object_test.cpp

#include "object_construction.hpp"
//#include <iostream>

void copyCtor(Object test) {
    
}


int main() {

    // default ctor
    Object one;
    Object two;

    // = operator
    one = two;
    two = one;

    // copy ctor
    copyCtor(one); //Tests copy ctor
    copyCtor(two); //Tests copy ctor

    // dtor should be called as exiting program
    return 0;
}
