#include "LinkedList/LinkedList.h"

#include <iostream>

#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>


int main()
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//
	LinkedList<int> list;
	list.Insert(30);
	list.Insert(10);
	list.Insert(40);
	list.Insert(60);
	std::cout << "노드 추가 후 출력\n";
	list.Print();

	

	list.Delete(30);
	list.Delete(40);
	std::cout << "노드 삭제 후 출력\n";
	list.Print();

	std::cin.get();
}