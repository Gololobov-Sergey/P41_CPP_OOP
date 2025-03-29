#pragma once


class Array
{
	int* arr;
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
		arr = new int[size];
	}

	~Array()
	{
		delete arr;
	}

	void set()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % 10;
		}
	}

	void set(int min, int max)
	{
		for (int i = 0; i < size; i++)
		{
			arr[i] = rand() % (max - min + 1) + min;
		}
	}

	void print()
	{
		for (int i = 0; i < size; i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

	void add(int value)
	{
		int* temp = new int[size + 1];
		for (size_t i = 0; i < size; i++)
		{
			temp[i] = arr[i];
		}
		temp[size] = value;
		delete arr;
		size++;
		arr = temp;
	}

	void insert(int value, int index)
	{
		int* temp = new int[size + 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		temp[index] = value;
		for (size_t i = index; i < size; i++)
		{
			temp[i + 1] = arr[i];
		}
		delete arr;
		size++;
		arr = temp;
	}

	void remove(int index)
	{
		int* temp = new int[size - 1];
		for (size_t i = 0; i < index; i++)
		{
			temp[i] = arr[i];
		}
		for (size_t i = index; i < size - 1; i++)
		{
			temp[i] = arr[i + 1];
		}
		delete arr;
		size--;
		arr = temp;
	}

	int sum()
	{
		int sum = 0;
		for (size_t i = 0; i < size; i++)
		{
			sum += arr[i];
		}
		return sum;
	}

	int max()
	{
		int max = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (arr[i] > max)
			{
				max = arr[i];
			}
		}
		return max;
	}

	int min()
	{
		int min = arr[0];
		for (size_t i = 1; i < size; i++)
		{
			if (arr[i] < min)
			{
				min = arr[i];
			}
		}
		return min;
	}

	int count(int value)
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

	double average()
	{
		return (double)sum() / size;
	}

	int getSize()
	{
		return size;
	}

};

