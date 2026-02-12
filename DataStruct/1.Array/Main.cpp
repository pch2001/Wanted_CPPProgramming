#include <iostream>
#include <cassert>


//템플릿으로 배열 만들기
template<typename T, size_t size = 5>
class Array
{
public : 
	size_t Size() const
	{
		return size;
	}
	
	T& operator[](size_t index)
	{
		//어써트 (꼭 검증이 필요한 구문에 활용)
		//디버그 모드에서만 동작
		//assert(false);
		//ssert(index < 0 || index >= size);
		// 인덱스 범위 확인
		if (index < 0 || index >= size)
		{
			__debugbreak();
		}
		return data[index];
	}

	const T& operator[](size_t index) const
	{
		return data[index];
	}

private : 
	//
	int data[size] = {};
};


int main()
{
	Array<int, 10> array;
	array[3] = 20;
	const auto& arrayRefuernece = array;
	std::cin.get();
}