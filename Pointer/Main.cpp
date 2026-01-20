#include <iostream>

void DeletePointer(void*& pointer)
{
	if (pointer != nullptr)
	{
		delete pointer;
		pointer = nullptr;
	}
}

int main()
{
	//동적 할당
	char* buffer = new char[10];
	



	// 포인터는 주소를 저장하는 변수.
	//void* pointer = nullptr;
	void* pointer = new int;
	DeletePointer(pointer);
	//delete pointer;
	//pointer = nullptr;

	// null check.
	if (pointer != nullptr)
	{
		std::cout << "Pointer is not null\n";
	}
	else
	{
		std::cout << "Pointer is null\n";
	}

	// 의미는 없음.
	std::cin.get();
}