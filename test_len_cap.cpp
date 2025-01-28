//  String class test program
//
//  Tests: capacity and length
// 
  
#include "string.hpp"
#include <cassert>
#include <iostream>
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // capacity test

        // TEST
        String str = "abc";

        int result  = str.capacity();
        int result2 = str.length();

        // VERIFY
        assert(result  == 3);
        assert(result2 == 3);
    }
    {
        //------------------------------------------------------
        // length = 1

        // TEST
        String str = "1";

        int result  = str.capacity();
        int result2 = str.length();

        // VERIFY
        assert(result  == 1);
        assert(result2 == 1);
    }
    {
        //------------------------------------------------------
        // length = 3

        // TEST
        String str = ("123");

        int result  = str.capacity();
        int result2 = str.length();

        // VERIFY
        assert(result  == 3);
        assert(result2 == 3);
    }
    {
        //------------------------------------------------------
        // length = 53

        // TEST
        String  str("99999999999999999888888888237599988389383982981298214");

        int result  = str.capacity();
        int result2 = str.length();

        // VERIFY
        assert(result  == 53);
        assert(result2 == 53);
    }
    {
        //------------------------------------------------------
        // length is near capacity

        // TEST
        String  str ("2222224222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222221");

        int result  = str.capacity();
        int result2 = str.length();

        // VERIFY
        assert(result  == 241);
        assert(result2 == 241);
    }
    {
        //------------------------------------------------------
        // length is near capacity

        // TEST
        String  str ("888888888888899999999999999933333333333333333333333333374592748570237489888888888888888888888888888833333333333333333333333333333333333333374728987283475927389472465727347744444444444444444444444444444444444444444444444444444444444444444444444444444432145");

        int result  = str.capacity();
        int result2 = str.length();

        // VERIFY
        assert(result  == 255);
        assert(result2 == 255);
    }
    

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing capacity and length." << std::endl;
    return 0;
}
