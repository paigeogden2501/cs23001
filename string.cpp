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
    stringSize = 1;
    str = new char[stringSize];
    str[0] = 0;
}

// String('x')
String::String(char ch){
    if (ch == 0) {
        stringSize = 1;
    }
    else {
        stringSize = 2;
    }
    str = new char[stringSize];
    // the first element is the char
    str[0] = ch;
    // second element is null
    str[capacity()] = 0;
}

// String("abcd")
String::String(const char ch[]){

    // tracking size of ch
    int sizeTracker = 0;
    // find the size of the char array to assign it to stringSize
    while (ch[sizeTracker] != 0) {
        ++sizeTracker;
    }

    // assigning stringSize to the size of the ch array + a null element
    stringSize = ++sizeTracker;

    str = new char[stringSize];

    // tracker variable
    int i = 0;

    // until the char array is null
    while(ch[i] != 0) {
        // ensures that the size of the string array is not surpassed
        if (i >= stringSize) {
            break;
        }

        // assigns the string array to the value of the char array
        str[i] = ch[i];
        ++i;
    }

    // ensures str ends w a null element
    str[stringSize - 1] = 0;
}


// *********************** MILESTONE 2 STUFF ***********************
// destructor
String::~String() {
    stringSize = 0;
    delete[] str;
    // setting the str to equal SOMETHING
    //str = nullptr;
}

// copy constructor
String::String(const String& actual) {
    // setting the size equal
    stringSize = actual.stringSize;
    // making a new array of the new size
    str = new char[stringSize];

    // setting them equal
    for (int i = 0; i < stringSize; ++i) {
        str[i] = actual.str[i];
    }
}

// copy assignment 
// needs to handle a = a
String& String::operator=(String rhs) {
    // handles a = a
    // prevents a being deleted
    if (str == rhs.str) {
        return *this;
    }

    // deleting what str currently equals
    delete[] str;

    // assigning to the new size 
    stringSize = rhs.stringSize;

    // creating a new array
    str = new char[stringSize];

    // assigning the values from the rhs to the lhs
    for (int i = 0; i < stringSize; ++i) {
        str[i] = rhs.str[i];
    }

    return *this;
}

//Constant time swap
void String::swap(String& rhs) {
    // swapping the char array using a temporary pointer
    char* temp = str;
    str = rhs.str;
    rhs.str = temp;

    // swapping the string size member variable
    int stemp = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = stemp;
}
// **********************************************
//------------------------------------------

// ----- concatenation operators -----
// lhs = lhs + rhs
String& String::operator+=(const String& rhs) {

    // length of this str
    int lhsLen = length();
    // length of rhs str
    int rhsLen = rhs.length();
    // tracker variable for this.str index
    int i = 0;

    stringSize = lhsLen + rhsLen + 1;
    char* temp;
    temp = new char[stringSize];

    // assigning the lhs
    while (str[i] != 0) { 
        // ensuring bounds aren't surpassed
        if(!(i < lhsLen)) {
            break;
        }
        temp[i] = str[i];
        ++i;
    }

    // tracker variable for rhs
    int j = 0;

    // adds the rhs to the lhs
    while (rhs.str[j] != 0) {
        // ensures bounds aren't surpassed
        if(!(i < rhsLen + lhsLen)) {
            break;
        }
        temp[i] = rhs.str[j];
        ++j;
        ++i;
    }

    temp[stringSize - 1] = 0;

    delete[] str;
    str = temp;
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
    return (stringSize - 1);
}

//Sub from staring to ending positions
// REQUIRES 0 <= start <= end
String  String::substr (int start, int end) const {

    String result;
    int i = start;
    while (i <= end) {
	    result += str[i];
	    ++i;
    }
    // ending in null
    //result.str[i - start] = 0;

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

    while (position < (length() - key.length() + 1)) {
        if (key == substr(position, position + key.length() - 1) )
            return position;
        ++position;
    }
    return -1;
}

// input operator
std::istream& operator>>(std::istream& in, String& rhs) {
    
    int strSize = 300;

    // char to read in one word
    char ch[strSize];
    
    in >> ch;

    // checking if its not the end of the file
    if(!in.eof()) {
        // reassigning the right-hand side to the String 
        // cast of the char 
        rhs = String(ch);
    }
    // if it is the end of file, then the rhs 
    // is assigned an empty string
    else {
        rhs = String();
    }

    // return the istream
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

// *********************** MILESTONE 3 STUFF ***********************

std::vector<String> String::split(char splitCh) const {
    // tracker variables for str array
    int front = 0;
    int back = 0;

    // vector to hold split strings
    std::vector<String> result;

    // the char is found in the str
    while(back != -1) {
        // uses find char to find the position of the ch
        // returns the position of the char and assigns it to 
        // back; 
        // if not found, back == -1
        back = findch(front, splitCh);
         
        // if the position of the char is the front,
        // add an empty string on the vector
        if(front == back){
            result.push_back("");
        } 

        // if the char is found somewhere besides the front,
        // add a substring from the current front position
        // to before the char is found to the vector
        else if(back != -1) {
            result.push_back(substr(front, back - 1));
        }

        // if the char is not found,
        // add a substring from the current front position 
        // to the end of the str array to the vector
        if (back == -1) {
            result.push_back(substr(front, length()));
        }

        // increment the current front position to the
        // position after where the char was found
        front = back + 1;        
    }
    return result;
}

// *****************************************************************
