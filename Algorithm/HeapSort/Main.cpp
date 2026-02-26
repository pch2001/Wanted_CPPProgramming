#include <iostream>

// 배열을 힙으로 만드는 함수
// array : 정렬 중인 배열
// length : 배열 항목의 수
// index : 현재 처리 중인 인덱스
void Heapify(int* array, int length, int index)
{
	//힙 구성을 완료할 때까지 반복
	while (true)
	{
		// 최대힙(MaxHeap).
		int largest = index;

		// 자손 인덱스 구하기
		// 왼쪽 자손 : 2N +1;
		int leffChild = 2 * index + 1;

		// 오른쪽 자손 : 2N + 2;
		int rigthChild = 2 * index + 2; 

		// 왼쪽 자식이 존재하고 현재 노드보다 크면 largest를 왼쪽 자식으로 변경.
		if (leffChild < length && array[leffChild] > array[largest])
		{
			largest = leffChild;
		}
		// 오른쪽 자식이 존재하고 현재 노드보다 크면 largest를 오른쪽 자식으로 변경.
		if (rigthChild < length && array[rigthChild] > array[largest])
		{
			largest = rigthChild;
		}

		if (largest == index)
			break;

		// 현재 노드와 자손 노드(가장 큰 값을 가지는) 교환

		std::swap<int>(array[index], array[largest]);

		// largest를 현재 노드로 업데이트해 다음 반복에서 자식 노드와 비교
		index = largest;
	}


}


// 힙 정렬 함수 , Heapify를 사용하여 정렬
void HeapSort(int* array, int length)
{
	// 힙 구조로 변환.
	for (int ix = length / 2 - 1; ix >= 0; --ix)
	{
		Heapify(array, length, ix);
	}

	// 힙 정렬
	for (int ix = length - 1; ix > 0; --ix)
	{
		// 루트 노드와 마지막 노드(현재 노드)를 교환
		std::swap<int>(array[0], array[ix]);

		// 힙 구조를 유지하기 위해 루트 노드부터 다시 힙으로 만들기.
		Heapify(array, ix, 0);
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
		if ((ix + 1) % 10 == 0)
			std::cout << "\n";
	}
	std::cout << "\n";
}


int main()
{

	//int array[] = { 5, 2, 8, 4, 1, 7, 3, 6, 9, 10, 15, 13, 14, 12, 17, 16 };
	int array[] =
	{
		1, 58, 10, 20, 56, 63, 73, 5, 28, 37,
		80, 61, 82, 45, 11, 66, 83, 59, 22, 64,
		52, 89, 94, 76, 44, 40, 75, 2, 23, 57,
		92, 8, 41, 96, 15, 84, 35, 69, 54, 47,
		90, 24, 43, 74, 34, 85, 72, 95, 18, 17,
		98, 9, 29, 53, 27, 79, 39, 51, 31, 16,
		6, 97, 26, 100, 21, 48, 33, 60, 91, 19,
		30, 13, 71, 78, 87, 25, 81, 4, 42, 93,
		49, 12, 14, 7, 62, 77, 38, 99, 88, 50,
		32, 46, 70, 3, 86, 68, 36, 67, 55, 65
	};

	int length = _countof(array);

	//출력
	PrintArray(array, length);

	HeapSort(array, length);

	PrintArray(array, length);

}