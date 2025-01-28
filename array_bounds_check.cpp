// 
// Kent State University
// CS 23001 - J. Maletic
//
// Part of lab 6 on dynamic memory
//
// Memory allocation and array bounds checking
//
// C/C++ does not check array bounds, so accessing an element of an
//    array outside of its defined size results in Undefined Behavior
//
// TO COMPILE: clang++ -Wall array_bounds_check.cpp -o bounds_check
// TO RUN: ./bounds_check
//           Then enter a postivie interger value at the prompt
//
// Instructions:
//   Read the code.  Then run the program multiple times.  Examing the output.
//   If on wasp/hornet use values of 10, 16, 32, 33, 40
//   If on a Mac use values of 10 16, 17, 20
//
//   What is wrong with this code?
//~      As the input values increase (for str1), the amount of memory left between str1
//~      and str2 decreases, until there no longer any memory available between the two
//~      strs at all. Therefore, the elements that are supposed to initialize str1 when
//~      there is no longer memory in str1 are put in the memory for str2.
//   Why is no error raised?
//~      While there is memory available for the data to go, it is not in the right str.
//~      However, there IS memory available, which is all the compiler is concerned with.
//~      Therefore, there is not error because while the memory isn't for the right str,
//~      it is available. 
//   How many bytes are between the start of str1 and str2?
//~      5; str1 is allocated first with 5 bytes of memory while str2 is allocated directly after. 
//~      Therefore, there are 5 bytes of mem between the first element of str1 and the first 
//~      element of str2.
//   How could you test for this logical error?
//~      You can test for the error by doing what the instructions tell us to do, test mutliple 
//~      cases that are exhaustive and test bounds (the input we used tests the bounds of the 
//~      memory of str1)
//   How could you prevent this type of error?
//~      You could limit the input number the user inputs so that it does not exceed the 5 bytes
//~      of memory that are alloted for str1. You could also limit the for loop that initializes 
//~      str1 to not exceed its 5 bytes of memory
//
//   Include the delete[] at the end and recompile, what changes?


#include <iostream>


int main () {
    char *str1 = new char[5];     //Allocate two arrays on the heap
    char *str2 = new char[20];
    int n=0;

    std::cout  << "str1->char[5]" << std::endl;
    std::cout  << "str2->char[20]" << std::endl;
    std::cout  << "Enter positive integer value: ";  // n > 0
    std::cin >> n;

    std::cout  << "Write to array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Write to str1[0...n-1]
        str1[i] = 'X';
        std::cout << "str1[" << i << "] = 'X'" << std::endl;
    }

    std::cout  << "Contents of array str1:" << std::endl;
    for (int i = 0; i < n; ++i) {   //Print str1[0...n-1]
        std::cout << "str1[" << i << "] == " << "|" <<  str1[i] << "|" << std::endl;
    }

    std::cout  << "Contents of array str2:" << std::endl;
    for (int i = 0; i < 20; ++i) {    //Print str2[0...19]
        std::cout << "str2[" << i << "] == " << "|" <<  str2[i] << "|" << std::endl;
    }

    delete[] str1;
    delete[] str2;

    return 0;
}

