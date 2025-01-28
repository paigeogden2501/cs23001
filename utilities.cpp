// paige ogden
// 
// file: utilities.cpp
// commands to run:
// make postfix
// ./postfix input output
// ./postfix data3-1.txt postfixOutput.txt
// ./postfix data3-2-1.txt postfixOutput.txt
// ./postfix postfix_test.txt postfixOutput.txt

#include "utilities.hpp"

// ~milestone 2~
void infixToPostfix(std::ifstream& in, std::ostream& out) {
    stack<String> theString;
    // variable for the operators of the infix
    String rhs, lhs, op, token;
    char tempToken[300];

    out << "infix expression: ";
    
    // while it is not the end of the file
    while(!in.eof()) {
        
        // read in line
        in >> tempToken;
        //std::cout << tempToken;
        token = String(tempToken);

        // if the token is end of file token
        if (in.eof()) {
            break;
        }
        
        out << token << " ";

        // if it is the end of line character
        if (token == ";") {
            // print the top of stack, the postfix expression
            out << "\npostfix expression: "<< theString.top() << "\n";
            // call the assembly func for the postfix expression
            out << postfixToAssembly(theString.top(), out);
            out << "\n\n";
            out << "infix expression: ";

            // clears the stack
            theString = stack<String>();
        }
        // if it is the end parenthesis
        else if (token == ")") {
            // assigning the rhs, op, and lhs terms
            rhs = theString.pop();
            op = theString.pop();
            lhs = theString.pop();
            // adding them to the stack in postfix order
            theString.push(lhs + rhs + op);
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


// ~milestone 3~
String postfixToAssembly(String pfExpres, std::ostream& out) {

    out << "postfix to assembly: \n";
    // creates substrings for each term in the postfix
    std::vector<String> token = pfExpres.split(' ');

    // stack used to put the rhs, lhs, and op on
    stack<String> theString;
    String rhs, lhs, op, result, temp;
    // tracks the number of temp variables
    int num = 1;
    
    // iterate for each term in the vector
    for(size_t i = 0; i != token.size(); ++i) {
        // if a math operation needs to be performed
        if (token[i] == "+" || token[i] == "-" || token[i] == "*" || token[i] == "/") {
            rhs = theString.pop();
            lhs = theString.pop();
            // figure out which op is being used
            result = evaluateAssembly(rhs, lhs, token[i], out);
            temp = "TMP" + integerToString(num);
            // psuhing a "temp" term on the stack
            // to hold the answer of the math prob
            theString.push(temp);
            // increment the temp tracker
            ++num;
            // save the answer
            out << "     ST     " << temp << "\n";
        }
        // for every other char, push it on the stack
        else {
            theString.push(token[i]);
        }
    }
    return theString.top();
}

String evaluateAssembly(String rhs, String lhs, String op, std::ostream& out) {
    // loading in the "new" term
    out << "     LD     " << lhs << "\n";

    // figuring out which operator is being used
    if (op == '+') {
        out << "     AD     ";
    }
    else if (op == '-') {
        out << "     SB     ";
    }
    else if (op == '*') {
        out << "     MU     ";
    }
    else if (op == '/') {
        out << "     DV     ";
    }
    else {
        out << "     UNDEF     ";
    }

    // outputting the rhs term
    out << rhs << "\n";
    // putting the three terms together, 
    // in infix order
    return lhs + op + rhs;
}

String integerToString(int x) {

    if (!x) {
        return "0";
    }

    String result;

    // if x == 0
    result = result + (x % 10 + 48);
    x = x / 10;

    while (x > 0) {
        result = result + (x % 10 + 48);
        x = x / 10;
    }

    return result;
}
