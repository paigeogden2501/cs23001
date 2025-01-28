// paige ogden
// 
// 4/3/2024
// 
// file: assembler.cpp
// read infix from file and output the postfix to postfixOutput.txt
// commands to run:
// make assembler
// ./assembler input output
// ./assembler data3-1.txt postfixOutput.txt
// ./assembler data3-2-1.txt postfixOutput.txt
// ./assembler postfix_test.txt postfixOutput.txt

#include "utilities.hpp"

int main(int argc, char const* argv[]) {

    // the input file is not specified
    if (argc < 2) {
        std::cerr << "User did not enter an input file\n";
    }


    // opening input file
    std::ifstream ifile (argv[1]);
    // if the file was not open correctly
    if (!ifile) {
        std::cerr << "Unable to open the input file\n";
    }

    // opening output file
    std::ofstream ofile(argv[2]);

    // if an output file is not specified, cout is to be used
    if (!ofile) {
        infixToPostfix(ifile, std::cout);
    }

    // calling the method
    infixToPostfix(ifile, ofile);

    ifile.close();
    ofile.close();

    std::cout << "\nDone testing infix to postfix\n";

    return 0;
}
