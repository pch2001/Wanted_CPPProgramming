#include <iostream>
#include <functional>
#include <vector>
#include <array>
//typedef int (*Adder) (int a, int b);

//using Adder = int(*)(int a, int b);

using Adder = std::function<int(int, int)>;

//int Function(int a, int b, std::function<int(int, int)> adder)

int Function(int a, int b, Adder adder)
{
	return adder(a, b);
	
}

int Add(int a, int b) { return a + b;  }


class Operator
{
public:
	int Add(int a, int b);

};


int main()
{
	std::vector<int> arr;
	int (*FunctionPointer)();
	//FunctionPointer = Funtion();
	std::array<int, 3> a = {};

	std::cout << Function(10, 20, Add) << "\n";

	std::cout << 100;

	std::cin.get();
}