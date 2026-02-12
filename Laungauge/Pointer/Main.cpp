#include <iostream>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
// Replace _NORMAL_BLOCK with _CLIENT_BLOCK if you want the
// allocations to be of _CLIENT_BLOCK type
#else
#define DBG_NEW new
#endif

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>

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
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//_CrtSetBreakAlloc(156);

	// todo 메모리 릭 일부러 발생시키기
	int* intPointer = DBG_NEW int; // DBG_NEW -> new 변경
	delete intPointer;

	//동적 할당
	//char* buffer = new char[10];
	



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

	//todo : fuck


	std::cin.get();
}