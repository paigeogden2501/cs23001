// 
// 
// 

#ifndef CS2_UTILITIES_HPP_
#define CS2_UTILITIES_HPP_

#include <iostream>
#include <fstream>
#include "stack.hpp"
#include "../string/string.hpp"


// converts infix to postfix
void infixToPostfix(std::ifstream& in, std::ostream& out);

// converts postfix to assembly
String postfixToAssembly(String pfExpres, std::ostream& out);

// evaluates what the assembly line should be
String evaluateAssembly(String rhs, String lhs, String op, std::ostream& out);

String integerToString(int x);

#endif
