#pragma once

template<typename T, size_t Size>
class Stack
{
public :
	Stack() : top(0) {}
	void Clear() { top = 0; }
	bool IsEmpty() const { return top == 0; }
	bool IsFull() const { return top >= Size; }
	
	bool Push(const T& value)
	{
		if (IsFull()) return false;

		data[top] = value;
		top++;
		return true;
	}
	
	T Pop()
	{
		if (IsEmpty()) return false;
		top--;
		return data[top];
	}

	size_t Capacity() const
	{
		return Size;
	}

private :
	int top;
	T data[Size];

};