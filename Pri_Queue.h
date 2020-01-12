/*
 * Queue.h
 *
 *  Created on: 03-Jan-2020
 *      Author: g10
 */

#ifndef PRI_QUEUE_H_
#define PRI_QUEUE_H_
#include<iostream>

namespace std {


template <class T>
class Pri_Queue {
	//class Node;
	struct Node
	{
		public :
		int priority;
		T data;
	    Node* next;
	};
	Node *front, *rear;

public:
	Pri_Queue();
	void enqueue(T data);
	T dequeue();
	int isEmpty();
	void display();
	//void priority(T data);
	virtual ~Pri_Queue();
};

} /* namespace std */

#endif /* PRI_QUEUE_H_ */
