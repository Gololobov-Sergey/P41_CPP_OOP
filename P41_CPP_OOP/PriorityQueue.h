#pragma once
#include<iostream>
#include<initializer_list>

#include "Node.h"

using namespace std;


template<class T, class TPri = int>
class PriorityQueue
{
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last  = nullptr;
	size_t         size  = 0;

	


public:
	PriorityQueue();
	PriorityQueue(initializer_list<T> list);
	PriorityQueue(const PriorityQueue& obj);
	PriorityQueue& operator=(const PriorityQueue& obj);
	~PriorityQueue();

	void enqueue(T value, TPri priority);
	void dequeue();
	T& peek();

	void clear();
	void print(int count = -1);
	size_t length();

};

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue()
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(initializer_list<T> list)
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>::PriorityQueue(const PriorityQueue& obj)
{
}

template<class T, class TPri>
PriorityQueue<T, TPri>& PriorityQueue<T, TPri>::operator=(const PriorityQueue& obj)
{
	// TODO: вставьте здесь оператор return
}

template<class T, class TPri>
PriorityQueue<T, TPri>::~PriorityQueue()
{
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::enqueue(T value, TPri priority)
{
	Node<T, TPri>* newNode = new Node<T, TPri>(value, priority);

	if (size == 0)
	{
		first = last = newNode;
		size++;
		return;
	}

	if (priority <= last->priority)
	{
		last->next = newNode;
		last = newNode;
	}
	else if (priority > first->priority)
	{
		newNode->next = first;
		first = newNode;
	}
	else
	{
		Node<T, TPri>* pos = first;
		while (priority <= pos->next->priority)
		{
			pos = pos->next;
		}
		newNode->next = pos->next;
		pos->next = newNode;
	}
	size++;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::dequeue()
{
	if (size > 0)
	{
		Node<T, TPri>* temp = first;
		first = first->next;
		delete temp;
		size--;
		if (size == 0)
			last = nullptr;
	}
}

template<class T, class TPri>
T& PriorityQueue<T, TPri>::peek()
{
	return first->value;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::clear()
{
	Node<T, TPri>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T, class TPri>
void PriorityQueue<T, TPri>::print(int count)
{
	Node<T, TPri>* temp = first;
	int i = 0;
	while (temp)
	{
		cout << temp->value;
		temp = temp->next;
		i++;
		if (i == count)
			break;
	}
	cout << endl;
}

template<class T, class TPri>
inline size_t PriorityQueue<T, TPri>::length()
{
	return size;
}
