#include <iostream>
#include "string"
#include <Windows.h>

#define MyTest(x,y) x*y+1234

class Player {
public:
	//생성자(Contrcutor) 객체를 생성할 때 호출되는 함수
	Player(const char* inName) {
		//name = inName; 불가능
		
		// 1. 저장 공간 확보 -> 확보할 공간의 크기를 알아야 함
		size_t length = strlen(inName) + 1;
		name = new char[length];

		// 2. 문자열 복사
		for (int ix = 0; ix < length; ++ix) {
			name[ix] = inName[ix];
		}

		strcpy_s(name, length, inName);
	
	}
	~Player() {
		if (name != nullptr) {
			delete[] name;
		}
	}

private :
	char* name = nullptr;
};

int main() {

	//문자열 
	//문자열은 불변성을 가짐
	const char* testString = "hoo";
	std::cout << testString << "\n";

	char buffer[4] = { 'h', 'o', 'o' , 0 };
	std::cout << buffer << "\n";


	Player player("hoohoohoo");



	//wide-character
	const wchar_t* wideString = TEXT("Hello wide string");
	std::wcout <<  wideString << TEXT("\n");
	auto a = MyTest(33, 44);
	std::cin.get();

}