//File:        string.cpp
//       
//Version:     1.1
//Date:        Spring 2024
//Author:      Dr. J. Maletic
//
//Description: Interface definition of String class for Project 2, milestone 1.
//
// To use the supplied test oracles you will need to use this interface and namings.
// You must also have all of these methods and functions defined for your string class.
//
// You will either have use this interface or call your methods through this interface.
//
// You need to implement all of the methods and funcitons declared here.
//

#include "string.hpp"
#include <cassert>
//#include <iostream>


// CLASS INV:   str[length()] == 0 &&
//              0 <= length() <= capacity() &&
//              capacity() == STRING_SIZE - 1


// ----- CONSTRUCTORS -----

// empty string
String::String() {
    // the string is empty
    // therefore the null element is the first element
    str[0] = 0;
}

// String('x')
String::String(char ch){
    // the first element is the char
    str[0] = ch;
    // second element is null
    str[1] = 0;
}

// String("abcd")
String::String(const char ch[]){

    // tracker variable
    int i = 0;

    // until the char array is null
    while(ch[i] != 0) {
        // ensures that the size of the string array is not surpassed
        if (i >= capacity()) {
            break;
        }

        // assigns the string array to the value of the char array
        str[i] = ch[i];
        ++i;
    }

    // ensures str ends w a null element
    str[i] = 0;
}
//------------------------------------------

// ----- concatenation operators -----
// lhs = lhs + rhs
String& String::operator+=(const String& rhs) {

    // length of this str
    int offset = length();
    // length of rhs str
    int rhsLen = rhs.length();
    // tracker variable
    int i = 0;

    // for the rhs 
    while (i < rhsLen) {
        // ensuring that the max of the array isn't reached
	    if (offset >= capacity()) {
            break;
        }
        // accounts for the lhs string and adds the rhs string after
	    str[offset + i] = rhs.str[i];
	    ++i;
    }
    // ends w null
    str[offset + i] = 0;
    return *this;
}

String  operator+(String lhs, const String& rhs) {

    // using the class function to access the str
    // using += to do the operation
    lhs += rhs;
    return lhs;
}
//------------------------------------------


// ----- RELATIONAL OPERATORS -----

// ==
bool String::operator==(const String& rhs) const {

    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] == rhs.str[i];

}

// < 
bool String::operator<(const String& rhs) const {
    
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i])) ++i;
    return str[i] < rhs.str[i];

}

// using alr defined == and String() casting 
bool operator== (const char lhs[],  const String& rhs) { 
    return String(lhs) == rhs; 
}

bool operator== (char lhs, const String& rhs) { 
    return String(lhs) == rhs; 
}

bool operator< (const char lhs[], const String& rhs) {
    return String(lhs) < rhs;
}

bool operator< (char lhs, const String& rhs) {
    return String(lhs) < rhs;
}

bool operator<= (const String& lhs, const String& rhs) {
    return !(rhs < lhs);
}

bool operator!= (const String& lhs, const String& rhs) { 
    return !(lhs == rhs); 
}

bool operator>= (const String& lhs, const String& rhs) {
    return !(lhs < rhs);
}

bool operator> (const String& lhs, const String& rhs) {
    return rhs < lhs;
}

//------------------------------------------


// ---------------- METHODS ----------------

// accessor modifier
// REQUIRES: 0 <= a < length()
char& String::operator[] (int a) {
    assert(a >= 0);
    assert(a < length());

    return str[a];
}

// accessor
// REQUIRES: 0 <= a < length()
char String::operator[] (int a) const {
    assert(a >= 0);
    assert(a < length());

    return str[a];
}

// number of char in string
int String::length() const {
    int result = 0; 

    // accounts for all elements except null
    while(str[result] != 0) {
        ++result;
    }

    return result;
}

// max chars that can be stored
int String::capacity() const {
    return STRING_SIZE-1;
}

//Sub from staring to ending positions
// REQUIRES 0 <= start <= end
String  String::substr (int start, int end) const {
    // requirements and
    // taking care of nonsense cases :)
    if (start < 0) {
        start = 0;
    }
    if (end >= length()) {
        end = length() - 1;
    }
    if (start > end) { 
        return String();
    }


    String result;
    int i = start;
    while (i <= end) {
	    result.str[i - start] = str[i];
	    ++i;
    }
    // ending in null
    result.str[i - start] = 0;

    //std::cout << "\nprinting out substr result " << result << "\n\n";
    return result;
}

//Location of charater starting at a position
int String::findch(int start,  char ch) const {

    // starting point to search for ch
    int i = start;

    while(str[i] != 0) {
        // if found, return the location/index
        if (str[i] == ch) {
            return i;
        }
        ++i;
    }
    // if not found, return -1
    return -1;
}

//Location of string starting at a position
int String::findstr(int start,  const String& key) const {
    int position = start;

    while (position < (length() - key.length())) {
        if (key == substr(position, position + key.length() - 1) )
            return position;
        ++position;
    }
    return -1;
}

// input operator
std::istream& operator>>(std::istream& in, String& rhs) {
/*
    char ch[STRING_SIZE];

    if (in.eof()) return in;
    else {
        if(in.eof())
            return in;
        in >> ch;
    }

    rhs = String(ch);

    return in;
*/
char ch[STRING_SIZE];

in >> ch;

if (!in.eof()) {
    rhs = String(ch);
}
else {
    rhs = String();
}

   return in; 
}

// output operator
std::ostream& operator<<(std::ostream& out, const String& rhs) {

    // tracker
    int i = 0;

    // while rhs is not null
    while(rhs.str[i] != 0) {
        // output the elements of index i of string rhs
        out << rhs.str[i];
        ++i;
    }
    
    // return the ostream
    return out;
}

//------------------------------------------
