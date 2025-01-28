// paige ogden
// 4/2/2024
// file: infix2prefix.cpp
//
// commands to run:
// clang++ -Wall  infix2prefix.cpp ../string/string.hpp ../assembler/stack.hpp ../string/string.cpp
// ./a.out 


#include <fstream>
//#include <vector>
#include <iostream>
#include "../assembler/stack.hpp"
#include "../string/string.hpp"


void infixToPrefix(std::ifstream& in, std::ostream& out);

void infixToPrefix(std::ifstream& in, std::ostream& out) {
    stack<String> theString;
    // variable for the operators of the infix
    String rhs, lhs, op, token;
    char tempToken[100];

    // while it is not the end of the file
    while(!in.eof()) {

        // read in line
        in >> tempToken;
        token = String(tempToken);

        // if the token is end of file token
        if (in.eof()) {
            break;
        }

        // if it is the end of line character
        if (token == ";") {
            // print the top of stack, the prefix expression
            out << theString.top() << " " << "\n";
            // clears the stack
            theString = stack<String>();
        }
        // if it is the end parenthesis
        else if (token == ")") {
            // assigning the rhs, op, and lhs terms
            rhs = theString.pop();
            op = theString.pop();
            lhs = theString.pop();
            // adding them to the stack in prefix order
            theString.push(op + lhs + rhs);
        }
        // for any other character
        else {
            if (token != "(") {
                // essentially pushes the variables on the stack
                theString.push(token + ' ');
            }
        }
    }

}

int main() {

    // opening file
    std::ifstream file ("data3-1.txt");
    // if the file was not open correctly
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
    }

    // calling the method
    infixToPrefix(file, std::cout);

    file.close();

    return 0;
}
