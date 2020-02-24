/*
 * Queue.h
 *
 *  Created on: 03-Jan-2020
 *      Author: g10
 */

#ifndef QUEUE_H_
#define QUEUE_H_
#include<iostream>

namespace std {


template <class T>
class Queue {
	//class Node;
	struct Node
	{
		public : 
		//int priority;
		T data;
	    Node* next;
	};
	Node *front, *rear;

public:
	Queue();
	void enqueue(T data);
	T dequeue();
	int isEmpty();
	//void priority(T data);
	virtual ~Queue();
};

} /* namespace std */

#endif /* QUEUE_H_ */
