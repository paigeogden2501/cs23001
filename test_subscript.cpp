// bigint Test Program
//
// Tests:  subscript, uses ==
//
// NEED TO IMPLEMENT
// 
#include <iostream>
#include <cassert>
#include "bigint.hpp"

//===========================================================================
int main () {
    
    {
        // Setup
        bigint bi(4);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 4);  //Wrong.  Will FAIL.  Fix and add test cases.
        assert(digit == 4);
    }
    
    //Add test cases!!

    {
        // Setup
        bigint bi(12345);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 12345);  
        assert(digit == 4);
    }
    {
        // Setup
        bigint bi(0);

        // Test 
        int digit = bi[0];

        // Verify
        assert(bi    == 0);  
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi("9876543210");

        // Test 
        int digit = bi[5];

        // Verify
        assert(bi    == "9876543210");  
        assert(digit == 5);
    }
    {
        // Setup
        bigint bi("4300050032111187666789087223");

        // Test 
        int digit = bi[23];

        // Verify
        assert(bi    == "4300050032111187666789087223");  
        assert(digit == 0);
    }
    {
        // Setup
        bigint bi("9817234098723140987123409871230982347982374912340198092734");

        // Test 
        int digit = bi[33];

        // Verify
        assert(bi    == "9817234098723140987123409871230982347982374912340198092734");  
        assert(digit == 9);
    }
    {
        // Setup
        bigint bi(800);

        // Test 
        int digit = bi[2];

        // Verify
        assert(bi    == 800);  
        assert(digit == 8);
    }
    {
        // Setup
        bigint bi(26);

        // Test 
        int digit = bi[1];

        // Verify
        assert(bi    == 26);  
        assert(digit == 2);
    }
    {
        // Setup
        bigint bi(44772219);

        // Test 
        int digit = bi[4];

        // Verify
        assert(bi    == 44772219);  
        assert(digit == 7);
    }
    {
        // Setup
        bigint bi("222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");

        // Test 
        int digit = bi[57];

        // Verify
        assert(bi    == "222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");  
        assert(digit == 2);
    }
    {
        // Setup
        bigint bi("500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");

        // Test 
        int digit = bi[197];

        // Verify
        assert(bi    == "500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");  
        assert(digit == 5);
    }

    std::cout << "Done testing subscript." << std::endl;
    return 0;
}
