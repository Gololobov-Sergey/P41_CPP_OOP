#pragma once
#include<iostream>
#include<initializer_list>

#include "Node.h"

using namespace std;

template<class T>
class ForwardList
{
	Node<T>* first = nullptr;
	Node<T>* last = nullptr;
	size_t   size = 0;

	Node<T>* getNode(int index);

public:
	ForwardList();
	ForwardList(initializer_list<T> list);
	ForwardList(const ForwardList& list);
	ForwardList& operator=(const ForwardList& list);
	~ForwardList();

	void push_front(T value);
	void push_back(T value);
	void insert(T value, int index);

	void pop_front();
	void pop_back();
	void remove(int index);

	T front();
	T back();
	T at(int index);

	T& operator[](int index);

	void clear();
	void print();

	void reverse();
	void sort();

	void for_each(void(*method)(T&));

	size_t length();

	ForwardList<T> operator+(const ForwardList<T>& list);

};

template<class T>
Node<T>* ForwardList<T>::getNode(int index)
{
	Node<T>* pos = first;
	for (size_t i = 0; i < index; i++)
	{
		pos = pos->next;
	}
	return pos;
}

template<class T>
ForwardList<T>::ForwardList()
{
}

template<class T>
ForwardList<T>::ForwardList(initializer_list<T> list)
{
	for (auto elem : list)
	{
		this->push_back(elem);
	}
}

template<class T>
ForwardList<T>::ForwardList(const ForwardList& list)
{
}

template<class T>
ForwardList<T>& ForwardList<T>::operator=(const ForwardList& list)
{
	// TODO: вставьте здесь оператор return
}

template<class T>
ForwardList<T>::~ForwardList()
{
	this->clear();
}

template<class T>
void ForwardList<T>::push_front(T value)
{
	if (size == 0)
	{
		first = last = new Node<T>(value);
	}
	else
	{
		Node<T>* newNode = new Node<T>(value);
		newNode->next = first;
		first = newNode;
	}
	size++;
}

template<class T>
void ForwardList<T>::push_back(T value)
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
void ForwardList<T>::insert(T value, int index)
{
	if (index == 0)
	{
		this->push_front(value);
	}
	else if (index == size)
	{
		this->push_back(value);
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* newNode = new Node<T>(value);
		newNode->next = pos->next;
		pos->next = newNode;
		size++;
	}
}

template<class T>
void ForwardList<T>::pop_front()
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
void ForwardList<T>::pop_back()
{
	if (size > 0)
	{
		if (size == 1)
		{
			delete first;
			first = last = nullptr;
		}
		else
		{
			last = getNode(size - 2);
			delete last->next;
			last->next = nullptr;
		}
		size--;
	}
}

template<class T>
void ForwardList<T>::remove(int index)
{
	if (index == 0)
	{
		this->pop_front();
	}
	else if (index == size - 1)
	{
		this->pop_back();
	}
	else
	{
		Node<T>* pos = getNode(index - 1);
		Node<T>* temp = pos->next;
		pos->next = pos->next->next;
		delete temp;
		size--;
	}
}

template<class T>
T ForwardList<T>::front()
{
	return first->value;
}

template<class T>
T ForwardList<T>::back()
{
	return last->value;
}

template<class T>
T ForwardList<T>::at(int index)
{
	return getNode(index)->value;
}

template<class T>
T& ForwardList<T>::operator[](int index)
{
	return getNode(index)->value;
}

template<class T>
void ForwardList<T>::clear()
{
	Node<T>* temp = first;
	while (temp)
	{
		first = first->next;
		delete temp;
		temp = first;
	}
	first = last = nullptr;
	size = 0;
}

template<class T>
void ForwardList<T>::print()
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
void ForwardList<T>::sort()
{
	for (size_t i = 0; i < size - 1; i++)
	{
		for (size_t j = 0; j < size - 1 - i; j++)
		{
			Node<T>* node = getNode(j);
			if (node->value > node->next->value)
			{
				swap(node->value, node->next->value);
			}
		}
	}
}

template<class T>
void ForwardList<T>::for_each(void(*method)(T& elem))
{
	Node<T>* temp = first;
	for (size_t i = 0; i < size; i++)
	{
		method(temp->value);
		temp = temp->next;
	}
}

template<class T>
size_t ForwardList<T>::length()
{
	return size;
}
