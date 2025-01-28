//  Stack class test program
//
//  Tests: destructor
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
        x.push(0);

        x.~stack();

        // VERIFY
        assert(x.empty() == true);
        assert(x.full()  == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  a;
        a.push(1);
        a.push(2);
        a.push(3);
        a.push(4);
        a.push(5);
        a.push(6);
        a.push(7);
        a.push(8);
        a.push(9);
        a.push(0);

        a.~stack();

        // VERIFY
        assert(a.empty() == true);
        assert(a.full()  == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  b;
        b.push('#');


        b.~stack();

        // VERIFY
        assert(b.empty() == true);
        assert(b.full()  == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  c;
        c.push('a');
        c.push('b');
        c.push('c');
        c.push('d');
        c.push('e');
        c.push('f');
        c.push('g');
        c.push('h');
        c.push('i');
        c.push('j');

        c.~stack();

        // VERIFY
        assert(c.empty() == true);
        assert(c.full()  == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  d;
        d.push("abc");

        d.~stack();

        // VERIFY
        assert(d.empty() == true);
        assert(d.full()  == false);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  e;
        for(int i = 0; i < 300; ++i)    {
            e.push("hello");
        }

        e.~stack();

        // VERIFY
        assert(e.empty() == true);
        assert(e.full()  == false);
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing test_dtor.cpp." << std::endl;
    return 0;
}

