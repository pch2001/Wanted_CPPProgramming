#include <iostream>
#include <Windows.h>
//삽입 정렬 함수
void InsertaionSort(int* array, int length)
{
	//예외 처리
	if (length <= 1)
		return;

	//	  [8][5][7][2][4]
	// 1: [5][8] [6][2][4]
	// 2: [5][6][8] [2][4]
	// 3: [2][5][6][8] [4]
	// 4: [2][4][5][6][8]
	
	//배열 순회
	for (int ix = 1; ix < length; ++ix)
	{
		//현재 삽입할 값
		int key = array[ix];
		int jx = ix - 1;

		//key보다 큰 값은 오른쪽으로 배치
		while (jx >= 0 && array[jx] > key)
		{
			array[jx + 1] = array[jx];
			--jx;
		}

		//적절한 위치에 key 삽입
		array[jx + 1] = key;
	}
}

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
	//자료 집합
	int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	//배열 항목 개수 구하기
	int length = ARRAYSIZE(array);

	//정렬 전 출력
	std::cout << "정렬 전 배열";
	PrintArray(array, length);

	//정렬
	InsertaionSort(array, length);
	
	//정렬 후 출력
	std::cout << "정렬 후 배열";
	PrintArray(array, length);

}

