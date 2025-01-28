// bigint Test Program
//
// Tests:  int constructor, uses ==
// 
// NEED TO IMPLEMENT
//
#include <iostream> 
#include <cassert>
#include "bigint.hpp"


//===========================================================================
int main () {
    {

        // VERY INCOMPLETE set of tests.


        //------------------------------------------------------
        // Setup fixture
        bigint left(0);
        bigint right(0);
        bigint result;

        // Test 
        result = left + right;

        // Verify
        assert(left   == 0);
        assert(right  == 0);
        assert(result == 0);
    }

    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(0);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 0);
      assert(result == 1);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 1);
      assert(result == 2);
    }
    
    
    //Add test cases as needed.
    
    
    {
    //------------------------------------------------------
    // Setup fixture
    bigint left(9);
    bigint right(1);
    bigint result;

    // Test
    result = left + right;

      // Verify
      assert(left   == 9);
      assert(right  == 1);
      assert(result == 10);
    }
    {
    //------------------------------------------------------
    // Setup fixture
    bigint left(1);
    bigint right(9);
    bigint result;

    // Test
    result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 9);
      assert(result == 10);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(111);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 111);
      assert(right  == 1);
      assert(result == 112);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(99);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 99);
      assert(right  == 1);
      assert(result == 100);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(1);
      bigint right(99);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 1);
      assert(right  == 99);
      assert(result == 100);
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left(999);
      bigint right(1);
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == 999);
      assert(right  == 1);
      assert(result == 1000);
    }
    {
    //------------------------------------------------------
    // Setup fixture
    bigint left(123456789);
    bigint right(123456789);
    bigint result;

    // Test
    result = left + right;

      // Verify
      assert(left   == 123456789);
      assert(right  == 123456789);
      assert(result == 246913578);
    }
    {
    //------------------------------------------------------
    // Setup fixture
    bigint left("999999999999999999999999999999999999999");
    bigint right(1);
    bigint result;

    // Test
    result = left + right;
    std::cout << left << " + " << right << " = " << result << std::endl;

      // Verify
      assert(left   == "999999999999999999999999999999999999999");
      assert(right  == 1);
      assert(result == "1000000000000000000000000000000000000000");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("1111110000000000000000000000000000000000000000000000000000000000000000011111");
      bigint right("5000000000000000000000000000000000000000000000000000000000000000000000022222");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "1111110000000000000000000000000000000000000000000000000000000000000000011111");
      assert(right  == "5000000000000000000000000000000000000000000000000000000000000000000000022222");
      assert(result == "6111110000000000000000000000000000000000000000000000000000000000000000033333");
    }
    {
      //------------------------------------------------------
      // Setup fixture
      bigint left("500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      bigint right("380000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      assert(right  == "380000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      assert(result == "880000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
    }
    {
      //------------------------------------------------------
      // using 198 digits
      // Setup fixture
      bigint left("222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");
      bigint right("500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      bigint result;

      // Test
      result = left + right;

      // Verify
      assert(left   == "222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");
      assert(right  == "500000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000");
      assert(result == "722222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222");
    }

    
    std::cout << "Done with testing addition." << std::endl;
    return 0;
}

