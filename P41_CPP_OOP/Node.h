#pragma once

template<class T>
struct Node
{
	T     value;
	Node* next;

	Node(T value) : value(value), next(nullptr) {}
};
