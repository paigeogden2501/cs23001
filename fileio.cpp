// lab 4
// paige ogden
// 2/6/2024
// reading a text file

#include <iostream>
#include <fstream>


// function prototypes
void outputsText();
void addTwoNums();


int main () {

outputsText();

std::cout << "\n\n";

addTwoNums();

}

// function definition

// reads all text up to a space and outputs that text
void outputsText() {
    // opening the file
    std::ifstream file ("fileio-text.txt");
    // if the file was not open correctly
    if (!file.is_open()) {
        std::cout << "Unable to open file\n";
    }


    char ch;
    file.get(ch);

    // while the end of the file hasn't been reached
    while (!file.eof()) {
        // while the character isn't a space character
        if (ch != ' ') {
            std::cout << ch;
            file.get(ch);
        }
        else{
            file.get(ch);
            std::cout << "\n";
        }        
    }

    // close the file 
    file.close();
}



// reads two ints, adds them, prints the results
void addTwoNums() {
    // opening the file
    std::ifstream file ("fileio-data-1.txt");

    // variables for storing ints in one line
    int first = 0;
    int second = 0;

    char ch;

    // while the end of the file hasn't been reached
    while (!file.eof()) {
        
        // reading the first int
        file >> first;

        // reading the second int
        file.get(ch);
        file >> second;

        file.get(ch);

        // ensures the end of file isn't reached 
        if (!file.eof()) {
            // outputs the sum
            std::cout << first + second;
            std::cout << "\n";
        }

    }

    // close the file 
    file.close();

}
