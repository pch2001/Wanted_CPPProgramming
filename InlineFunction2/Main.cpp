#include <iostream>

//매크로(Macro)
//#define Square(x) ((x)*(x))
//인라인 함수는 속도 때문에 사용

#define FORCEINLINE __forceinline
FORCEINLINE int Square2(int x) {
	return x * x;
}

inline int Square(int x) {
	return x * x;
}

int main() {
	int number = Square(10);

	std::cout << number;
}