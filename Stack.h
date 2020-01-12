/*
 * Stack.h
 *
 *  Created on: 18-Dec-2019
 *      Author: g10
 */

#ifndef STACK_H_
#define STACK_H_
#include <iostream>

template <class T>
class Stack {
	 struct node{
	    T data;
		struct node* next;
	};
	struct node* top;
public:
	Stack();
	void push(T x);
	T pop();
	T peep();
	int isEmpty();
	virtual ~Stack();
};


#endif /* STACK_H_ */
