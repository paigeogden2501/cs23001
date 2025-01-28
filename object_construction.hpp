// object_construction.hpp
// 2/26/2024
// Paige Ogden

#include <iostream>

#ifndef Object_Construction
#define Object_Construction

class Object {
public:
//default ctor
Object();

// destructor dtor
~Object();

// copy ctor
Object (const Object&);

// assignment (standard version)
Object operator=(const Object&);

private:

};

#endif
