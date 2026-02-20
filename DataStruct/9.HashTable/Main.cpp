
#include <iostream>

int main()
{

	int number = 10;
	int number2 = 20;
	int& ref = number;
	int* ref2 = &number;
	ref = number2;
	ref = std::move(number2);
}