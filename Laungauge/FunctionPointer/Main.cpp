//#include <iostream>
//#include <functional>
////typedef int (*Adder) (int a, int b);
//
////using Adder = int(*)(int a, int b);
//
//using Adder = std::function<int(int, int)>;
//
////int Function(int a, int b, std::function<int(int, int)> adder)
//
//int Function(int a, int b, Adder adder)
//{
//	return adder(a, b);
//	
//}
//
//int Add(int a, int b) { return a + b;  }
//
//
//class Operator
//{
//public:
//	int Add(int a, int b);
//
//};
//
//
//int main()
//{
//	int (*FunctionPointer)();
//	//FunctionPointer = Funtion();
//	
//	std::cout << Function(10, 20, Add) << "\n";
//
//	std::cout << 100;
//
//	std::cin.get();
//}

#include <iostream>
#include <vector>
#include <algorithm>
//Functor(함수 객체)
class Less
{
public:
	//호출 연산자 오버로딩
	bool operator()(int a, int b) {
		return a < b;
	}

};

//Functor(함수 객체)
class Greater
{
public : 
	//호출 연산자 오버로딩
	bool operator()(int a, int b) {
		return a > b;
	}
private : 
	int count;
	//상태도 추가로 관리하가능
};


int main()
{
	//정렬할 배열
	std::vector<int> arr = { 1,2,3,4,5,6,7,8,9,10 };
	


	//함수 객체 생성
	Less less;
	Greater GREATER;

	//std::sort(arr.begin(), arr.end(), GREATER);

	//람다
	auto greater = [](int a, int b) -> bool { return a > b;  };
	int number1 = 10;
	int number2 = 5;

	bool result = greater(number1, number2);

	std::sort(arr.begin(), arr.end(), [](int a, int b)->bool {return a > b; });

	int sum = 0;
	std::for_each(arr.begin(), arr.end(), [&sum](int item) {sum += item; });
	std::cout << "sum : " << sum <<"\n";

	for (const auto item : arr)
	{
		std::cout << item << " ";
	}
	std::cout << "\n";

	std::cin.get();
}