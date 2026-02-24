#pragma once

#include <iostream>

template<typename T, int capactiy = 10>
class Stack
{
public :

	Stack() : top(0) {}
	Stack(T data) : top(0) { Push(data); }

	bool Push(const T& value)
	{
		if (IsFull())
			return false;

		data[top] = value;
		top++;
		return true;
	}
	bool Pop(T& outValue)
	{
		if (IsEmpty())
			return false;
		--top;
		outValue = data[top];
		return true;
	}

	void Print()
	{
		int temp = top;
		for (int i = top; i >= 0; --i)
		{
			std::cout << data[i] <<"\n";
		}
	}

	inline bool IsFull() { return top == capactiy; }
	inline int Count() { return top; }
	inline bool IsEmpty() { return top == 0; }

private :
	T data[capactiy] = {};
	int top;
};