//  String class test program
//
//  Tests: char ctor 
// 
  
#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // empty char

        // TEST
        String  str(' ');

        // VERIFY
        assert(str == ' ');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('X');

        // VERIFY
        assert(str == 'X');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('Y');

        // VERIFY
        assert(str == 'Y');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('2');

        // VERIFY
        assert(str == '2');
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        String  str('9');

        // VERIFY
        assert(str == '9');
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing ctor char." << std::endl;
    return 0;
}
