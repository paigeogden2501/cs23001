// big int milestone 1
// started 1/23/2024
// Paige Ogden

// header inclusion
#ifndef BIGINT_HPP_
#define BIGINT_HPP_

// global constant
const int CAPACITY = 200;

class bigint {
public:
	//default constructor
	//initializes numArray to zero
	bigint();

	//constr to initialize to an int value provided
	bigint(int);

	//constr to initialize to an char provided
	bigint(const char a[]);

	//debugging bigint method
	void debugPrint(std::ostream&) const;

	// overload operator to compare if two bigints are equal
	friend bool operator==(bigint lhs, bigint rhs);

	// ---------- MILESTONE 2 FUNC HEADERS ----------

	// overload output operator as a friend function
	friend std::ostream& operator<<(std::ostream& out, bigint rhs);

	// overload + operator to add two bigints together
	bigint operator+ (const bigint&) const;

	// const version overload subscript op. returns the digit in the 10^i position
	int operator[] (int) const;

	// non const version subscript op.
	int& operator[] (int);

	// overload >> op. read in any number of digits until a semi colon
	friend std::istream& operator>> (std::istream& file, bigint& rhs);

	// ---------- MILESTONE 3 FUNC HEADERS ----------

	// multiplication method
	bigint timesDigit(int) const;

	// multiply a bigint by 10^n
	bigint times10(int) const;

	// overloading * to multiple two bigints using the timesDigit and times10
	bigint operator* (bigint& rhs);


private:
	int numArray[CAPACITY];

};


#endif
