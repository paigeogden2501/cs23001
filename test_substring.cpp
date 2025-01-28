//  String class test program
// 
//  Tests: substring
//
  
#include "string.hpp"
#include <cassert>
#include <iostream> 
 
//===========================================================================
int main ()
{
    {
        //------------------------------------------------------
        // testing getting an empty string
        String  str("hi");

        // TEST
        String result = str.substr(0, 0);

        // VERIFY
        assert(str    == "hi");
        assert(result == "h");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Hello");

        // TEST
        String result = str.substr(2,4);

        // VERIFY
        assert(str    == "Hello");
        assert(result == "llo");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("Pookie bear");

        // TEST
        String result = str.substr(0, 5);

        // VERIFY
        assert(str    == "Pookie bear");
        assert(result == "Pookie");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("I miss my friends from high school. They all go to colleges that are auper far from home, and I never get to see them. I wish we could see each other more.");

        // TEST
        String result = str.substr(150, 153);

        // VERIFY
        assert(str    == "I miss my friends from high school. They all go to colleges that are auper far from home, and I never get to see them. I wish we could see each other more.");
        assert(result == "more");
    }

    {
        //------------------------------------------------------
        // SETUP FIXTURE
        String  str("The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks.");

        // TEST
        String result = str.substr(41, 44);

        // VERIFY
        assert(str    == "The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks.");
        assert(result == "Yogi");
    }

    {
        //------------------------------------------------------
        // Testing near bounds
        String  str("The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks. His favorite place to go on a walk is the Poland woods because there is a fenced-in yard with a horse that he loves to play with.");

        // TEST
        String result = str.substr(80, 86);

        // VERIFY
        assert(str    == "The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks. His favorite place to go on a walk is the Poland woods because there is a fenced-in yard with a horse that he loves to play with.");
        assert(result == "CRAZY!!");
    }

    // ADD ADDITIONAL TESTS AS NECESSARY
    
    std::cout << "Done testing substring." << std::endl;
    return 0;
}

