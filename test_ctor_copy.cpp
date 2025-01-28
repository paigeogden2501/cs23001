//  Stack class test program
//
//  Tests: copy constructor
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
        stack<int> one;
        one.push(1);

        stack<int> two(one);
        
        // VERIFY
        assert(one.top() == two.top()); 
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char> one;
        one.push('~');

        stack<char> two(one);
        
        // VERIFY
        assert(one.top() == two.top()); 
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> one;
        one.push("abc");

        stack<String> two(one);
        
        // VERIFY
        assert(one.top() == two.top()); 
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<int> one;
        one.push(1);
        one.push(2);
        one.push(3);
        one.push(4);
        one.push(5);
        one.push(6);
        one.push(7);
        one.push(8);
        one.push(9);
        one.push(0);


        stack<int> two(one);
        
        // VERIFY
        assert(one.top() == two.top()); 
        assert(one.pop() == two.pop()); 
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<char> one;
        one.push('a');
        one.push('b');
        one.push('c');
        one.push('d');
        one.push('e');
        one.push('f');
        one.push('g');
        one.push('h');
        one.push('i');
        one.push('j');

        stack<char> two(one);
        
        // VERIFY
        assert(one.pop() == two.pop()); 
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop());
        assert(one.pop() == two.pop()); 
    }
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        stack<String> one;
        for(int i = 0; i < 300; ++i)    {
            one.push("hello");
        }

        stack<String> two(one);
        
        // VERIFY
        for(int i = 0; i < 300; ++i)    {
            assert(one.pop() == two.pop());
        }
    }


    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing copy constructor." << std::endl;
    return 0;
}

