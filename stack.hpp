// paige ogden
//
// file: stack.hpp
//

#ifndef STACK_HPP
#define STACK_HPP

#include <new>
#include <cassert>
#include "stack-interface.hpp"
#include "../string/string.hpp"

// default constructor
template <typename T>
stack<T>::stack() {
	// top of stack is zero, the stack is empty
	tos = 0;
}

// copy constructor
template <typename T>
stack<T>::stack(const stack<T>& actual) {

	// temp node to increment through actual
	Node<T>* temp = actual.tos;
	// node to increment through *this
	Node<T>* bottom = 0;
	// initializing the pointer
	tos = 0;

	// while there is a node
	while (temp != 0) {
		// if *this does not have any nodes
		if (tos == 0) {
			// make a node that is the data 
			// of the first node in actual
			tos = new Node<T>(temp->data);
			// setting the bottom to *this 
			// top of stack
			bottom = tos;
		}
		// if there is a node in *this
		else {
			// add a node of the data of temp and 
			// set next pointer to it
			bottom->next = new Node<T>(temp->data);
			// incrementing bottom (to be the ~bottom~)
			bottom = bottom->next;
		}
		// incrementing temp to the next actual node
		temp = temp->next;
	}
	
}

// destructor
template <typename T>
stack<T>::~stack() {
	Node<T>* temp;
	// while the top of stack is not zero (empty)
	while (tos != 0) {
		// temp equals the current top of stack to later delete
		temp = tos;
		// top of stack equals the next node 
		tos = tos->next;
		// deleting the old top of stack
		delete temp;
	}
}

// swap
template <typename T>
void stack<T>::swap(stack<T>& rhs) {
	// a temp pointer
	Node<T>* temp = tos;
	// swapping the pointers of the two stacks
	tos = rhs.tos;
	rhs.tos = temp;
}

// = operator
template <typename T>
stack<T>& stack<T>::operator=(stack<T> rhs) {
	// setting the lhs to equal the rhs
	swap(rhs);
	// returning the lhs
	return *this;
}

// empty
template <typename T>
bool stack<T>::empty() const {
	// if tos is 0, then the stack is empty and returns true
	// else, the stack is not empty and returns false
	return tos == 0;
}

// full
template <typename T>
bool stack<T>::full() const {
	// making a temp node at max cap without having an
	// exception thrown
	Node<T>* temp = new(std::nothrow) Node<T>();
	if (temp == 0) {
		return true;
	}
	delete temp;
	return false;
}

// top
template <typename T>
T stack<T>::top() const {
	// returning the data of the first node
	return tos->data;
}

// pop
template <typename T>
T stack<T>::pop() {
	// the stack cannot be empty
	assert(!empty());

	// the return value has to be the data of the top node
	T result = tos->data;

	Node<T>* temp = tos;
	// removing the top node by pointing to the next one in the stack
	tos = tos->next;
	// delete the pointer pointing to the top of stack
	delete temp;
	return result;
}

// push
template <typename T>
void stack<T>::push(const T& item) {
	assert(!full());

	// creating a new node with the data
	Node<T>* temp = new Node<T>(item);
	// setting the new nodes next to the top of stack
	temp->next = tos;
	// setting the top of stack to the new node
	tos = temp;
}

#endif
