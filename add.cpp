// milestone 2 
// add.cpp
// 2/12/2024
// paige ogden

#include <iostream> 
#include <fstream>
#include <cstdlib>
#include "bigint.hpp"

int main() {

    //Until end of file
       //Read two bigints
       //Print them out
       //Add them together
       //Print out results

    std::ifstream in;        

    // open the file
    in.open("data1-1.txt");   

    // checking if file was opened    
    if(!in) {                    
        std::cerr << "File not found: data1-1.txt" << std::endl;
        exit(1);
    }

    bigint one("");
    in >> one;

    std::cout << "outputting the first number (one): " << one << "\n\n";

    bigint two("");
    in >> two;

    std::cout << "outputting the second number (two): " << two << "\n\n";

    std::cout << "the sum of one + two: " << one + two << "\n\n";

    std::cout << "---end of the first set of numbers---";
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
            std::cout << "the sum of one + two: " << one + two << "\n\n";
            std::cout << "---end of the current set of numbers---\n\n";
        }
    }

    // closing file
    in.close();

}
