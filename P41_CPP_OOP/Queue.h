#pragma once
#include<iostream>
#include<initializer_list>

//#include "Node.h"
#include "BaseQueue.h"

using namespace std;


template<class T>
class Queue : public BaseQueue<T>
{

public:

	void enqueue(T value);

	void ring();
};

template<class T>
void Queue<T>::enqueue(T value)
{
	if (this->size == 0)
	{
		this->first = this->last = new Node<T>(value);
	}
	else
	{
		this->last->next = new Node<T>(value);
		this->last = this->last->next;
	}
	this->size++;
}

template<class T>
void Queue<T>::ring()
{
	/*enqueue(peek());
	dequeue();*/

	this->last->next = this->first;
	this->first = this->first->next;
	this->last = this->last->next;
	this->last->next = nullptr;

}


