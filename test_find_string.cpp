// find string

//  String class test program
// 
//  Tests: find string method
//
  
#include "string.hpp"
#include <cassert>
#include <iostream> 
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
        String s = "a";

        // TEST
        int result = str.findstr(1, s);
        //std::cout << "\nprinting out result" << result << "\n";

        // VERIFY
        assert(str    == "abc");
        assert(result == -1);
        //std::cout << "Done testing test 1." << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("This is a text statment that will have a return value.");
        String s = "value";

        // TEST
        int result = str.findstr(25, s);
        //std::cout << "\nprinting out result" << result << "\n\n";

        // VERIFY
        assert(str    == "This is a text statment that will have a return value.");
        assert(result == 48);
        //std::cout << "Done testing test 2." << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
        String s = 'd';

        // TEST
        int result = str.findstr(0, s);
        //std::cout << "\nprinting out result" << result << "\n\n";

        // VERIFY
        assert(str    == "abc");
        assert(result == -1);
        //std::cout << "Done testing test 3." << std::endl;
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("abc");
        String s = 'a';

        // TEST
        int result = str.findstr(0, s);
        //std::cout << "\nprinting out result" << result << "\n\n";

        // VERIFY
        assert(str    == "abc");
        assert(result == 0);
        //std::cout << "Done testing test 4." << std::endl;
    }

    {
        //------------------------------------------------------
        // testing near bounds
        String  str("2222224222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222221");
        String s = "4";

        // TEST
        int result = str.findstr(0, s);

        // VERIFY
        assert(str    == "2222224222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222222221");
        assert(result == 6);
    }

    {
        //------------------------------------------------------
        // testing near bounds
        String  str("The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks. His favorite place to go on a walk is the Poland woods because there is a fenced-in yard with a horse that he loves to play with.");
        String s = 't';

        // TEST
        int result = str.findstr(0, s);

        // VERIFY
        assert(str    == "The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks. His favorite place to go on a walk is the Poland woods because there is a fenced-in yard with a horse that he loves to play with.");
        assert(result == 11);
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing find string." << std::endl;
    return 0;
}

