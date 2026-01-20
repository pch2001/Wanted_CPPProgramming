#include <iostream>
#include "Log.h"
//ctrl + 방향키 좌우
//F12, ctrl + -
//alt + shift + 아래 방향키
//void Log(const char* message) {
//	std::cout << message << "\n";
//}

int main() {
	//std::cout << "Hello World\n";
	
	Log("Hello world");


	//프로그램 바로 종료되지 말라고 붙이는거
	std::cin.get();

}	