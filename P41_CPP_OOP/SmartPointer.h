#pragma once


template<class T>
class SmartPointer
{
	T* ptr;

public:
	SmartPointer(T* ptr) : ptr(ptr)
	{

	}

	SmartPointer(const SmartPointer& obj)
	{
		ptr = new T;
		*ptr = *obj.ptr;
	}

	SmartPointer(SmartPointer&& obj)
	{
		ptr = obj.ptr;
		obj.ptr = nullptr;
	}

	SmartPointer& operator=(const SmartPointer& obj)
	{
		if (&obj == this)
			return *this;

		delete ptr;

		ptr = new T;
		*ptr = *obj.ptr;

		return *this;
	}


	~SmartPointer()
	{
		delete ptr;
	}

	T* operator->()
	{
		return ptr;
	}

};