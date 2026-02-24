#include <iostream>

// 함수 포인터 타입 지정
using Comparer = bool(*)(int,int);

//함수 포인터 화용
bool IsGreater(int left, int right)
{
	return left > right;

}
bool IsLess(int left, int right)
{
	return left < right;
}

//함수 Function / 메소드(Method)


//버블 정렬 함수
//비교 조건 확인 로직을 Comparer에게 맡김 -> 위임
// -> Delegate(델리게이트)
void BubbleSort(int* array, int length, Comparer comparer)
{
	for (int ix = 0; ix < length - 1; ++ix)
	{
		for (int jx = 0; jx < length - 1 - ix; ++jx)
		{
			//비교.
			if (comparer(array[jx], array[jx+1]))
			{
				//교체.
				std::swap<int>(array[jx], array[jx + 1]);
			}
		}
	}

}

// 배열 항목 출력 함수
void PrintArray(int* array, int length)
{
	for (int ix = 0; ix < length; ++ix)
	{
		std::cout << array[ix];
		//마지막 원소 전까지는 콤마 출력
		if (ix < length - 1)
		{
			std::cout << ", ";
		}
	}
	std::cout << "\n";
}


int main()
{
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };

	//배열길이
	int length = sizeof(array) / sizeof(array[0]);
	
	std::cout << "정렬 전 배열 : ";
	PrintArray(array, length);

	//정렬
	BubbleSort(array, length, IsGreater);
	std::cout << "정 정렬 후 배열 : ";
	PrintArray(array, length);

	//역정렬
	BubbleSort(array, length, IsLess);
	std::cout << "역 정렬 후 배열 : ";
	PrintArray(array, length);

}