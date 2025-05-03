#pragma once
#include <iostream>
#include <cassert>
#include "String.h"
#include "func.h"

using namespace std;

template<class T>
class Array
{
	T* arr;
	int size;

public:

	Array()
	{
		size = 0;
		arr = nullptr;
	}

	explicit Array(int s)
	{
		size = s;
		if (size != 0)
			arr = new T[size];
		else
			arr = nullptr;
	}

	Array(const Array& obj)
	{
		size = obj.size;
		arr = new T[size];
		for (size_t i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}

	~Array()
	{
		delete[] arr;
	}

	void set() const;

	void set(int min, int max) const
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print() const
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void print(int x, int y, int count) const
	{
		int start = (size < count) ? 0 : size - count;
		
		for (int i = start; i < size; i++)
		{
			gotoxy(x, y++);
			cout << arr[i];
		}
	}

	void add(T value)
	{
		T* temp = new T[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = value;
		delete[] arr;
		size++;
		arr = temp;
	}

	void insert(T value, int index)
	{
		T* temp = new T[size + 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = value;
		for (size_t i = index; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete[] arr;
		size++;
		arr = temp;
	}

	void remove(int index)
	{
		T* temp = new T[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		for (size_t i = index; i < size - 1; i++)
		{
			temp[i] = arr[i + 1];
		}
		delete[] arr;
		size--;
		arr = temp;
	}

	int sum() const
	{
		int sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}

	/*T max() const
	{
		T max = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}

	T min() const
	{
		T min = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}*/

	int count(T value) const
	{
		int count = 0;
		for (size_t i = 0; i < size; i++)
		{
			if (arr[i] == value)
			{
				count++;
			}
		}
		return count;
	}

	double average() const
	{
		return (double)sum() / size;
	}

	int getSize() const
	{
		return size;
	}

	T at(int index)
	{
		assert(index >= 0 && index < size);

		return arr[index];
	}

	T& operator[](int index)
	{
		assert(index >= 0 && index < size);

		return arr[index];
	}

	T& operator[](const char* index)
	{
		if (strcmp(index, "one") == 0)
			return arr[1];
	}


	void operator()(int value)
	{
		for (size_t i = 0; i < size; i++)
		{
			arr[i] += value;
		}
	}

	operator int()
	{
		return sum();
	}

	operator String ()
	{
		String s("");
		char buff[10];
		for (size_t i = 0; i < size; i++)
		{
			_itoa_s(arr[i], buff, 10);
			s += buff;
			s += " ";
		}
		return s;
	}
};



template<class T>
void Array<T>::set() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = T();
	}
}

template<>
void Array<int>::set() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 10;
	}
}

template<>
void Array<double>::set() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = 9.9999;
	}
}
