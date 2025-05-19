#pragma once
#include<iostream>
#include<initializer_list>

//#include "Node.h"
#include "BaseQueue.h"


using namespace std;


template<class T, class TPri = int>
class PriorityQueue : public BaseQueue<T, TPri>
{

public:
	void enqueue(T value, TPri priority);
};

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(T value, TPri priority)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);

	if (this->size == 0)
	{
		this->first = this->last = newNode;
		this->size++;
		return;
	}

	if (priority <= this->last->priority)
	{
		this->last->next = newNode;
		this->last = newNode;
	}
	else if (priority > this->first->priority)
	{
		newNode->next = this->first;
		this->first = newNode;
	}
	else
	{
		Node<T, TPri>* pos = this->first;
		while (priority <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	this->size++;
}