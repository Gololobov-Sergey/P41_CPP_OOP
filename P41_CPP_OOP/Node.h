#pragma once

template<class T, class TPri = int>
struct Node
{
	T     value;
	TPri priority;
	Node* next;
	Node* prev;

	Node(T value) : value(value), priority(TPri()), next(nullptr), prev(nullptr) {}
	Node(T value, TPri pri) : value(value), priority(pri), next(nullptr), prev(nullptr) {}
};
