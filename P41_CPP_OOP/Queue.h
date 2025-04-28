#pragma once
#include<iostream>
#include<initializer_list>

#include "Node.h"

using namespace std;


template<class T>
class Queue
{
	Node<T>* first = nullptr;
	Node<T>* last  = nullptr;
	size_t   size  = 0;

public:
	Queue();
	Queue(initializer_list<T> list);
	Queue(const Queue& obj);
	Queue& operator=(const Queue& obj);
	~Queue();

	void enqueue(T value);
	void dequeue();
	T& peek();

	void clear();
	void print();
	size_t length();

	void ring();
};

template<class T>
Queue<T>::Queue() { }

template<class T>
Queue<T>::Queue(initializer_list<T> list)
{
	for (auto elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T>
Queue<T>::Queue(const Queue& obj)
{
}

template<class T>
Queue<T>& Queue<T>::operator=(const Queue& obj)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
Queue<T>::~Queue()
{
	this->clear();
}

template<class T>
void Queue<T>::enqueue(T value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		last->next = new Node<T>(value);
		last = last->next;
	}
	size++;
}

template<class T>
void Queue<T>::dequeue()
{
	if (size > 0)
	{
		Node<T>* temp = first;
		first = first->next;
		delete temp;
		size--;
		if (size == 0)
			last = nullptr;
	}
}

template<class T>
T& Queue<T>::peek()
{
	return first->value;
}

template<class T>
void Queue<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	size = 0;
	last = nullptr;
}

template<class T>
void Queue<T>::print()
{
	Node<T>* temp = first;
	while (temp)
	{
		cout << temp->value << " ";
		temp = temp->next;
	}
	cout << endl;
}

template<class T>
size_t Queue<T>::length()
{
	return size;
}

template<class T>
void Queue<T>::ring()
{
	/*enqueue(peek());
	dequeue();*/

	last->next = first;
	first = first->next;
	last = last->next;
	last->next = nullptr;

}


