//  String class test program
// 
//  Tests: split
//
  
#include "string.hpp"
#include <cassert>
#include <iostream> 


int main() {

    {
        String s = "Good-morning-!";
        std::vector<String> result;

        result = s.split('-');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 3);
    }
    {
        String s = "abc ef gh";
        std::vector<String> result;

        result = s.split(' ');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 3);
    }
    {
        String s = "-a--b-";
        std::vector<String> result;

        result = s.split('-');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 5);
    }
    {
        String s = "Hello!How!Are!You!";
        std::vector<String> result;

        result = s.split('!');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 5);
    }
    {
        String s = "Today, is, a, great day!";
        std::vector<String> result;

        result = s.split(',');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 4);
    }
    {
        String s = "The dog went on a long walk. His name is Yogi. He is a golden retriever that is CRAZY!! . He loves to go on walks. His favorite place to go on a walk is the Poland woods because there is a fenced-in yard with a horse that he loves to play with.";
        std::vector<String> result;

        result = s.split('.');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 6);
    }
    {
        String s = "--abc-d-ef--ghi-j---kl--mno-p---q--rs-tuv---wx-y--z";
        std::vector<String> result;

        result = s.split('-');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 26);
    }
    {
        String s = "abc d ef ghi j kl mno p q rs tuv wx y z";
        std::vector<String> result;

        result = s.split(' ');

        std::cout << "size: " << result.size() << "\n";
        assert(result.size() == 14);
    }





    std::cout << "Done testing substring." << std::endl;
    return 0;
}
