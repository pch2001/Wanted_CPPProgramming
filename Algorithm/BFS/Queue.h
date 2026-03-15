#pragma once
#include <iostream>

template <typename T, size_t Size>
class Queue
{
public:
	Queue() : front(0), rear(0), size(Size + 1) {}

	bool IsEmpty() const { return front == rear; }
	bool IsFull() const { return (rear + 1) % size == front; }

	void Enqueue(const T& value)
	{
		if (IsFull())
		{
			std::cout << "큐가 가득 찼습니다.";
			return;
		}
		rear = (rear + 1) % size;
		data[rear] = value;
	}
	T Dequeue()
	{
		if(IsEmpty())
		{
			std::cout << "큐가 비어 있습니다.";
		}
		
		front = (front + 1) % size;
		return data[front];
	}


private:
	size_t front;
	size_t rear;
	size_t size;
	T data[Size + 1];
};