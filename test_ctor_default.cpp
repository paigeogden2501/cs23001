//  Stack class test program
//
//  Tests: ctor default
//

#include "stack.hpp"
#include <cassert>
#include <iostream>

//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;

        // VERIFY
        assert(x.empty() == true);
        assert(x.full() == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  a;

        // VERIFY
        assert(a.empty() == true);
        assert(a.full() == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  b;

        // VERIFY
        assert(b.empty() == true);
        assert(b.full() == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  c;

        // VERIFY
        assert(c.empty() == true);
        assert(c.full() == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  d;

        // VERIFY
        assert(d.empty() == true);
        assert(d.full() == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  e;

        // VERIFY
        assert(e.empty() == true);
        assert(e.full() == false);
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing test_ctor_default.cpp." << std::endl;
    return 0;
}

