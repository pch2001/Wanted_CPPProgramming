#include <iostream>
#include "Container/Stack.h"
#include "Container/Queue.h"

int main()
{
	Queue<std::string> inputQueue;
	Stack<std::string> undoStack;
	Stack<std::string> redoStack;
	
	while (true)
	{
		std::cout << "명령어를 입력해 주세요 (종료 Q) : ";
		std::string command;
		std::cin >> command;
		if (command == "Q" || command == "q")
		{
			std::cout << "종료하겠습니다.\n";
			break;
		}
		if (command == "undo")
		{
			std::cout << "undo 실행" << "\n";
			undoStack.Print();
		}
		else
		{
			std::cout << command <<" 명령어 삽입" << "\n";
			undoStack.Push(command);
		}
		

	}

}