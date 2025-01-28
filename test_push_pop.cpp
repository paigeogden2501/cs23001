//  Stack class test program
//
//  Tests: push and pop
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
        x.push(2);

        // VERIFY
        assert(x.empty() == false);
        assert(x.top()  == 2);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  x;
        x.push(2);
        x.pop();

        // VERIFY
        assert(x.empty() == true);
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
        a.pop();
        a.pop();
        a.pop();
        a.pop();
        a.pop();

        // VERIFY
        assert(a.empty() == false);
        assert(a.top()  == 5);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<char>  b;
        b.push('#');

        // VERIFY
        assert(b.empty() == false);
        assert(b.top()  == '#');
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
        c.pop();
        c.pop();
        c.pop();
        c.pop();
        c.pop();
        c.pop();
        c.pop();

        // VERIFY
        assert(c.empty() == false);
        assert(c.top()  == 'c');
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  d;
        d.push("abc");
        d.push("def");
        d.push("ghi");
        d.pop();

        // VERIFY
        assert(d.empty() == false);
        assert(d.top()  == "def");
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<String>  d;
        d.push("abcd");
        d.pop();


        // VERIFY
        assert(d.empty() == true);
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE

        // TEST
        stack<int>  e;
        for(int i = 0; i < 300; ++i)    {
            e.push(i);
        }

        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();
        e.pop();

        // VERIFY
        assert(e.empty() == false);
        assert(e.top()  == 282);
    }



    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing test_push_pop.cpp." << std::endl;
    return 0;
}

