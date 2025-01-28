// milestone 3
// multiply.cpp
// 2/26/2024
// paige ogden

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {

    // declaring in and opening the file
    std::ifstream in;
    in.open("data1-2.txt");

    // checking if file was opened    
    if(!in) {                    
        std::cerr << "File not found: data1-2.txt" << std::endl;
        exit(1);
    }


    bigint one("");
    in >> one;

    std::cout << "outputting the first number (one): " << one << "\n\n";

    bigint two("");
    in >> two;

    std::cout << "outputting the second number (two): " << two << "\n\n";

    std::cout << "the product of one and two: " << one * two << "\n\n";

    std::cout << "---end of the first set of numbers---\n";
    std::cout << "---outputting the rest of the numbers and their sums---";
    std::cout << "\n\n";


    while (!in.eof()) {

        // reading in "first number" and printing it
        in >> one;
        std::cout << "outputting the first number (one): " << one << "\n\n";

        // reading in "second number" and printing it
        in >> two;
        std::cout << "outputting the second number (two): " << two << "\n\n";

        if (!in.eof()) {
            // printing sum
            std::cout << "the product of one and two: " << one * two << "\n\n";
            std::cout << "---end of the current set of numbers---\n\n";
        }
    }

    // closing file
    in.close();


}
