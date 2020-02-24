/*
 * Queue.cpp
 *
 *  Created on: 03-Jan-2020
 *      Author: g10
 */
#include "Queue.h"

namespace std {
template <class T>
Queue<T>::Queue() {
	// TODO Auto-generated constructor stub
	rear = NULL;
	front = NULL;
}

template <class T>
int Queue<T> :: isEmpty()
{
	if(rear==NULL && front==NULL) return 1;
	else return 0;
}

template <class T>
void Queue<T> :: enqueue(T data)
{
	Node *newnode;
	newnode = new Node();
	newnode->data = data;
	if(rear==NULL && front==NULL){
		front = newnode;
		rear = newnode;
	}
	else{
		rear->next = newnode;
		rear = newnode;
	}
}

template <class T>
T Queue<T> :: dequeue()
{
	T x;
	Node *curr;
	if(front==NULL){
		cout << "\nError\n"; 
	}
	else{
		curr = front;
		x = curr->data;
		front = front->next;
		delete curr;
	}
	return x;
}

template <class T>
Queue<T>::~Queue() {
	// TODO Auto-generated destructor stub
}


}       /* namespace std */
