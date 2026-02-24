#pragma once

#include <iostream>

template <typename T, int capacity = 10>
class Queue
{
public:
	Queue() : first(0), end(0) {}
	Queue(T data) : first(0), end(0) { Push(data); }

	bool Push(const T& data)
	{
		if (IsFull())
			return false;

		data[end] = data;
		++end;
		return true;
	}

	bool Pop(T& outValue)
	{
		if (IsEmpty())
			return false;
		
		outValue = data[first];
		first++;
		return true;
	}

	inline bool IsFull() { return end == capacity; }
	inline int Count() { return end; }
	inline bool IsEmpty() { return first == end; }
private :
	T data[capacity] = {};
	int first=0;
	int end=0;
};