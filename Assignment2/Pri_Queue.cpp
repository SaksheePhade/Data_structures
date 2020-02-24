/*
 * Pri_Queue.cpp
 *
 *  Created on: 03-Jan-2020
 *      Author: g10
 */
#include "Pri_Queue.h"

namespace std {
template <class T>
Pri_Queue<T>::Pri_Queue() {
	// TODO Auto-generated constructor stub
	rear = NULL;
	front = NULL;
}

template <class T>
int Pri_Queue<T> :: isEmpty()
{
	if(rear==NULL && front==NULL) return 1;
	else return 0;
}

template <class T>
void Pri_Queue<T> :: enqueue(T data)
{
	Node *newnode;
	newnode = new Node();
	newnode->data = data;
	newnode->priority = newnode->data.getPriority(data.disease);
	newnode->next = NULL;
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
T Pri_Queue<T> :: dequeue()
{
	T x;
	int max_pri;
	Node *curr=front,*prev;
	Node *del;
	max_pri = curr->data.getPriority(curr->data.disease);
	if(front==NULL){
		cout << "\nError\n";
	}
	else{
		while(curr!=NULL){
			if(curr->data.getPriority(curr->data.disease) > max_pri)
				max_pri = curr->data.getPriority(curr->data.disease);
			curr = curr->next;
		}
		curr = front;
		while(curr!=NULL){
			if(curr->data.getPriority(curr->data.disease) == max_pri){
				if(curr==front){
					front = curr->next;
				}
				else if(curr==rear){
					prev->next = NULL;
					rear = prev;
				}
				else{
					prev->next = curr->next;
				}
				x = curr->data;
				delete curr;
				break;
			}
			prev = curr;
			curr = curr->next;
		}
	}
	return x;
}

template <class T>
void Pri_Queue<T> :: display()
{
	Node *curr=front;
	int i=0;
	while(curr!=NULL){
		i++;
		cout << "\t\t" << i  << "\t\t" << curr->data.name << "\t\t" << curr->data.id  << "\t\t" << curr->data.disease << "\t\t" << curr->data.phone << endl;
		curr = curr->next;
	}
}

template <class T>
Pri_Queue<T>::~Pri_Queue() {
	// TODO Auto-generated destructor stub
}


}       /* namespace std */
