#pragma once
#include <iostream>

template <typename T>
class Vector
{
public :
	Vector() : data(nullptr), size(0), capacity(0) { Reallocate(1); }
	~Vector(){ delete[] data; }

	void PushBack(const T& value)
	{
		if (size >= capacity)
			Reallocate(capacity * 2);
		data[size++] = value;
	}


	void Reallocate(int newCapacity)
	{
		T* newVector = new T[newCapacity];
		for (int i = 0; i < size; i++)
		{
			newVector[i] = data[i];
		}
		delete[] data;
		data = newVector;
		capacity = newCapacity;
	}

	T& operator[](int index) { return data[index]; }
	int Size() const { return size; }


private :
	T* data;
	int size;
	int capacity;
};