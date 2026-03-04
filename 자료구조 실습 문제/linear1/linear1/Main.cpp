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
			std::string temp;
			if (undoStack.Pop(temp))
			{
				redoStack.Push(temp);
			}
		}
		else if (command == "redo")
		{
			std::cout << "redo 실행" << "\n";
			std::string temp;
			if (redoStack.Pop(temp))
			{
				undoStack.Push(temp);
			}
		}
		else if (command == "show")
		{
			std::cout << "\n--- 현재 상태 ---" << "\n";
			std::cout << "Undo Stack: "; undoStack.Print(); std::cout << "\n";
			std::cout << "Redo Stack: "; redoStack.Print(); std::cout << "\n";
			std::cout << "----------------\n";
		}
		else
		{
			if (inputQueue.Push(command))
			{
				std::string temp;
				inputQueue.Pop(temp);
				undoStack.Push(temp);
			}
		}
		

	}

}