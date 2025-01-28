// file: recursion.cpp
// 3/5/2024
// paige ogden

#include <iostream>

// prototypes
int fibonacciTwo(int position, int one, int two);
int fibonacciOne(int position);


int main() {

    // prompt
    std::cout << "Enter a number: \n";
    int pos;
    std::cin >> pos;

    for (int i = 0; i <= pos; ++i) {
        std::cout << fibonacciOne(i) << " , ";
    }
    std::cout << "\n";


    // prompt
    std::cout << "Enter a number: \n";
    int pos2;
    std::cin >> pos2;

    for (int i = 0; i <= pos2; ++i) {
        std::cout << fibonacciTwo(i, 0, 1) << " , ";
    }
    std::cout << "\n";
}

// tail recursion
// returns the number in the fibonacci sequence that is at the position
int fibonacciTwo(int position, int one, int two) {
    // the two starting cases when n == 0
    if (position == 0) {
        return one;
    }
    // when n == 1
    if (position == 1) {
        return two;
    }

    // using the formula n-1 + n-2
    return fibonacciTwo(position - 1, two, one + two);

}

int fibonacciOne(int position) {
    // a shorter way of taking care of the two starting cases
    // when n == 0 or n == 1
    if (position <= 1) {
        return position;
    }

    // using the formula n-1 + n-2
    return fibonacciOne(position-1) + fibonacciOne(position-2);
}
