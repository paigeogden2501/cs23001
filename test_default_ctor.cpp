//  String class test program
//
//  Tests: default constructor
// 
  
#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // is default and only needs one test

        // TEST
        String  str;

        // VERIFY
        assert(str == '\0');
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing default constructor." << std::endl;
    return 0;
}
