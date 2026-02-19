#include "Container/Queue.h"

int main()
{
	//큐 객체 생성(현재 기본 크기는 10)
	Queue<int> queue;
	const int count = 10;

	for (int ix = 0; ix < count; ++ix)
	{
		queue.Enqueue(ix + 1);
	}

	queue.Print();

	int value;

	queue.Dequeue(value);
	queue.Dequeue(value);
	queue.Dequeue(value);

	queue.Print();

	//값 추가.
	queue.Enqueue(11);
	queue.Enqueue(12);
	queue.Print();

	std::cin.get();


}