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

    String a;
    while(in >> a) {
        std::cout << a << "\n";
    }
/*
    char ch[STRING_SIZE];
    while (in.getline(ch, STRING_SIZE)) {
        String input(ch);
        std::cout << input << "\n";
    }
*/

    in.close();

    std::cout << "Done testing input operator." << std::endl;
    return 0;
}
