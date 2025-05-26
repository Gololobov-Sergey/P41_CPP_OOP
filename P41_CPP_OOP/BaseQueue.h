#pragma once
#include<iostream>
#include<initializer_list>

#include "Node.h"

using namespace std;


template<class T, class TPri = int>
class BaseQueue
{
protected:
	Node<T, TPri>* first = nullptr;
	Node<T, TPri>* last = nullptr;
	size_t   size = 0;

public:
	BaseQueue();
	BaseQueue(initializer_list<T> list);
	BaseQueue(const BaseQueue& obj);
	BaseQueue& operator=(const BaseQueue& obj);
	~BaseQueue();



	void dequeue();
	T& peek();

	void clear();
	void print(int count = -1);
	void print(int x, int y, int count = -1);
	size_t length();

	void ring();
};

template<class T, class TPri>
BaseQueue<T, TPri>::BaseQueue() {}

template<class T, class TPri>
BaseQueue<T, TPri>::BaseQueue(initializer_list<T> list)
{
	for (auto elem : list)
	{
		this->enqueue(elem);
	}
}

template<class T, class TPri>
BaseQueue<T, TPri>::BaseQueue(const BaseQueue& obj)
{
}


template<class T, class TPri>
BaseQueue<T, TPri>& BaseQueue<T, TPri>::operator=(const BaseQueue& obj)
{
	// TODO: вставьте здесь оператор return
}

template<class T, class TPri>
BaseQueue<T, TPri>::~BaseQueue()
{
	this->clear();
}


template<class T, class TPri>
void BaseQueue<T, TPri>::dequeue()
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
T& BaseQueue<T, TPri>::peek()
{
	return first->value;
}

template<class T, class TPri>
void BaseQueue<T, TPri>::clear()
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
void BaseQueue<T, TPri>::print(int count)
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
inline void BaseQueue<T, TPri>::print(int x, int y, int count)
{
	Node<T, TPri>* temp = first;
	int i = 0;
	while (temp)
	{
		gotoxy(x, y++);
		cout << temp->value;
		temp = temp->next;
		i++;
		if (i == count)
			break;
	}
	cout << endl;
}

template<class T, class TPri>
size_t BaseQueue<T, TPri>::length()
{
	return size;
}

template<class T, class TPri>
void BaseQueue<T, TPri>::ring()
{
	/*enqueue(peek());
	dequeue();*/

	last->next = first;
	first = first->next;
	last = last->next;
	last->next = nullptr;
}