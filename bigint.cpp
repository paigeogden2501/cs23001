// milestone 1
// started 1/23/2024
// Paige Ogden

#include <iostream>
#include "bigint.hpp"

// constructors

// default
bigint::bigint() {
	// intializing the entire capacity of the array to 0
	for (int i = CAPACITY - 1; i >= 0; --i) {
		numArray[i] = 0;
	}
}

// initialize bigint to input value
bigint::bigint(int newNum) {
	// tracks the last digit of the number
	int digit;
	// contains the number
	int num = newNum;
	// initializes loop backwards (starting at max) for easier math later
	for (int i = CAPACITY - 1; i >= 0; --i) {
		if (num != 0) {
			// updates the last number
			digit = num % 10;
			numArray[i] = digit;
			// removes the last digit from the number
			num = num / 10;
		}
		else {
			numArray[i] = 0;
		}
	}
}

// initialize bigint to a const char
bigint::bigint(const char a[]) {

	// contains the number
	int num = 0;
	// used for char to int conversion
	char ch = '0';

	// finds length of char array
	int len = 0;
	while (a[len] != 0) {
		++len;
	}

	// tracker variable for the index of numArray
	int l = CAPACITY - 1;
	// initializes the end of numArray and converts the char to int
	for (int j = len - 1; j >= 0; --j) {
		ch = a[j];
		// converts char to int
		num = int(ch) - int('0');
		// assigns the bigint array to the char (now int)
		numArray[l] = num;
		--l;
	}

	// initializes the rest of the bigint array to 0
	while (l >= 0) {
		numArray[l] = 0;
		--l;
	}

}

// debugging bigint method
void bigint::debugPrint(std::ostream& cout) const {
	// iterates through the loop forwards to print the number correctly
	for (int i = 0; i < CAPACITY; ++i) {
		cout << numArray[i] << " | ";
	}
}

// overload output operator
std::ostream& operator<<(std::ostream& out, bigint rhs) {

	// this gets rid of the unnecessary leading zeros and assigns 
	// the starting index value of the number to j
	int j = 0;
	for (int k = 0; k < CAPACITY; ++k) {
		if (rhs.numArray[k] != 0) {
			j = k;
			break;
		}
	}

	// if the number in array is just zero
	if (j == 0) {
		out << "0";
	}
	// if the number is something other than zero
	else {
		// begins printing the number from the starting number
		for (int i = j; i < CAPACITY; ++i) {
			// prints at most 80 digits per line
			if (i == 160 || i == 120 || i == 80 || i == 40 || i == 0) {
				out << std::endl;
			}
			out << rhs.numArray[i];
		}
	}
	return out;
}

// overload operator to compare two bigints
bool operator==(bigint lhs, bigint rhs) {
	// iterates through the array backwards
	for (int i = CAPACITY - 1; i >= 0; --i) {
		if (lhs.numArray[i] != rhs.numArray[i])
			return false;
	}
	return true;
}



// ---------- MILESTONE 2 FUNC DEFINITIONS ----------

// overload + operator to add two bigints together
bigint bigint::operator+(const bigint& rhs) const {

	// tracks if there is a number to be carried over to next place value
	int carriedNum = 0;
	// bigint that is the sum of the bigints
	bigint total(0);

	// for duration of array
	for (int i = CAPACITY - 1; i >= 0; --i) {
		// adding a total
		int temp = numArray[i] + rhs.numArray[i] + carriedNum;
		// assigning the ones place value
		total.numArray[i] = temp % 10;
		// getting the tens place value (if applicable)
		carriedNum = temp / 10;
	}

	// returning sum
	return total;
}

// CONST VERSION overload subscript op. returns the digit in the 10^i position
int bigint::operator[] (int position) const {
	// works from the end of the array
	int result = CAPACITY - 1;

	// getting the digit where i is the 10^i position
	result = result - position;

	return numArray[result];
}

// CONST VERSION overload subscript op. returns the digit in the 10^i position
int& bigint::operator[] (int position) {
	// works from the end of the array
	int result = CAPACITY - 1;

	// getting the digit where i is the 10^i position
	result = result - position;

	return numArray[result];
}

// overload >> op. read in any number of digits until a semi colon
std::istream& operator>> (std::istream& in, bigint& rhs) {

	// creating a char array to read the numbers in
	char numbers[CAPACITY];

	// for the char
	char ch = ' ';

	// initializing the char array
	for (int j = 0; j < CAPACITY; ++j) {
		numbers[j] = 0;
	}

	// read in a ~token~ (or a whole number)
	in >> ch;
	// making sure i is not capacity and not a semi colon
	for (int i = 0; i < CAPACITY && ch != ';'; ++i) {
		// assigning it to the char array
		numbers[i] = ch;
		// reading in new num
		in >> ch;
	}

	// assigning the bigint to the char array
	rhs = numbers;

	return in;
}


// ---------- MILESTONE 3 FUNC DEFINITIONS ----------

// multiplying a bigint and a single digit integer between 0-9
bigint bigint::timesDigit(int integer) const {

	// tracks if there is a number to be carried over to next place value
	int carriedNum = 0;
	// bigint that is the product of the bigint and int
	bigint product(0);

	// for duration of array
	for (int i = CAPACITY-1; i >= 0; --i) {
		// holds product of one element and the int
		int temp = numArray[i] * integer + carriedNum;
		// assigning the ones place value of the product
		product.numArray[i] = temp % 10;
		// getting the tens place value (if applicable)
		carriedNum = temp / 10;
	}

	// returning product
	return product;
}

// multiply a bigint by 10^n
bigint bigint::times10(int integer) const {

	// bigint that is the bigint shifted to the left
	bigint product(0);
	// tracks the remaining after declaring the elements that need to be 0 in the product 
	int tracker = CAPACITY - 1;
	// used to access the elements in *this* numArray
	int tracker2 = CAPACITY - 1;

	// assigns 0 to the elements at the beginning of the array (one's place, ten's, etc)
	// so the other numbers can be shifted
	for (int j = 0; j < integer; ++j) {
		product.numArray[tracker] = 0;
		--tracker;
	}


	// for the remaining elements of the array
	// starts after the elements that were declared 0 
	// (where other loop ended)
	//std::cout << "\nentering 2nd loop of times10\n";
	for (int i = tracker; i > 0; --i) {
		product.numArray[i] = numArray[tracker2];
		--tracker2;
	}
	//std::cout << product << "\n";

	// returning product
	return product;
}

// overloading * to multiple two bigints using the timesDigit and times10
bigint bigint::operator* (bigint& rhs) {
	
	bigint product(0);
	bigint temp(0);
	// tracks the "tens place" value (how many zeroes need to be )
	int tracker = 0;

	for (int i = CAPACITY-1; i >= 0; --i) {
		// product = product + ((A * B[i]) * 10^i)
		//std::cout << "\ninteger: " << rhs.numArray[i] << "\n";
		temp = timesDigit(rhs.numArray[i]);
		//std::cout << "temp object: " << temp << "\n";
		product = product + temp.times10(tracker);
		++tracker;
		//std::cout << "the product: " << product << "\n";
	}

	return product;
}
