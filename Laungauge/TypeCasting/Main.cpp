#include <iostream>

void PrintString(char* string)
{
	std::cout << string << "\n";

}

class A{ 
public:
	virtual void Test(){}
};

class B : public A{
};

int main() 
{
	// const_cast
	const char* name = "hoo";
	PrintString(const_cast<char*>(name));

	//static_cast
	int number = 10;
	float floatNumber = static_cast<float>(number);

	

	//reinterpret_cast
	A* a = new A();
	B* b = static_cast<B*> (a);  //-> B를 A에 상속 해 주면 가능 , 잘 알고 써야함 class B {};는 불가능
	if (b) {
		std::cout << "b is not null\n";
	}

	B* b2 = reinterpret_cast<B*> (a);	// 상속이 없어도 가능 , 위험함
	if (b2) {
		std::cout << "b2 is not null\n";
	}
	//dynamic_cast
	B* b3 = dynamic_cast<B*>(a);	//다운캐스팅 이므로 해주지 않ㅇㅁ
	if (b3) {
		std::cout << "b3 is not null\n";
	}

	const type_info& ainfo = typeid(a);
	const type_info& binfo = typeid(b);

	if (ainfo == binfo) {
		std::cout << "Same\n";
	}

	std::cout << "Type of a is " << ainfo.name() << "\n";
	std::cout << "Type of a is " << binfo.name() << "\n";




	delete a;


	std::cin.get();

}