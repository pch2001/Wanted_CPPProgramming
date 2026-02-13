#include <iostream>

class Array
{
public:
	Array(size_t size)
	{
		// 오류 발생.
		data[size];
	}

private:
	int data[];
};

int main()
{
	Array(10);
	std::cin.get();

}