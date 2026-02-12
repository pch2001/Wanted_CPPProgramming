#include <iostream>

void printArray(int* array, int length) {

	//size_t size = sizeof(array);
	

	for (int ix = 0; ix < length; ++ix) {
		std::cout << array[ix] << "\n";
	}
}

int main() {
	// 배열 선언

	int array[10];
	memset(array, 0, sizeof(int) * 10);

	array[0] = 1;
	array[1] = 5;
	array[3] = 10;

	int* arrayPointer = array;
	arrayPointer[1] = 20;
	*(arrayPointer + 1) = 30;

	printArray(array, 10);
	/*for (const int& item : array) {
		std::cout << item << "\n";
	}*/


	//배열 동적 할당
	int* dynamicArray = new int[10];
	memset(dynamicArray, 1, sizeof(int) * 10);
	for (int ix = 0; ix < 10; ++ix) {
		dynamicArray[ix] = ix + 1;
	}

	delete[] dynamicArray;

	std::cin.get();
}