/*
 * Stack.cpp
 *
 *  Created on: 18-Dec-2019
 *      Author: g10
 */

#include "Stack.h"
using namespace std;

template <class T>
Stack<T> ::Stack() {
	// TODO Auto-generated constructor stub
	top = NULL;
}

template <class T>
void Stack<T> :: push(T x) {
	node* curr;
	curr = new node();
	curr->data = x;
	if(top == NULL){
		top = curr;
	}
	else{
		curr->next = top;
		top = curr;
	}
}

template <class T>
int Stack<T> :: isEmpty() {
	if(top==NULL) return 1;
	else return 0;
}

template <class T>
T Stack<T> :: pop() {
	T x=0;
	node* curr = NULL;
	if(top!=NULL){
		curr = top;
		x = curr->data;
		top = top->next;
		delete(curr);
	}
	else cout << "Stack is empty." << endl;
	return x;
}

template <class T>
T Stack<T> :: peep() {
	if(!isEmpty())
		return(top->data);
	else
		return 0;
}

template <class T>
Stack<T>::~Stack() {
	// TODO Auto-generated destructor stub
	node* curr;
	while(top!=NULL){
		curr = top;
		top = top->next;
		delete(curr);
	}
}
