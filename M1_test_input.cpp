//  String class test program
// 
//  Name:  test_input.cpp
//  Tests: input operator
//

#include "string.hpp"
#include <cassert>
#include <iostream>
#include <fstream>

int main() {

    std::ifstream in;
    in.open("test_input.txt");

    String input;
    while (in >> input) {
        std::cout << input << "\n";
    }

    in.close();

    std::cout << "\nDone testing input operator." << std::endl;
    return 0;
}
