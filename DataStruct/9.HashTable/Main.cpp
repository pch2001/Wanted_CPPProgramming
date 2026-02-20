#include "Container/HashTable.h"
#include <iostream>

/*
	int number = 10;
	int number2 = 20;
	int& ref = number;
	int* ref2 = &number;
	ref = number2;
	ref = std::move(number2);*/

int main()
{
	//해시 테이블 객체 생성
	HashTable table;

	//데이터 추가
	table.Add("Hoo", "010-12345");
	table.Add("Kebin", "010-12235");
	table.Add("SHOU", "010-56545");
	table.Add("MEE", "010-78945");
	table.Add("SHE", "010-34645");
	table.Add("Hoo", "010-74347");
	table.Add("HER", "010-25346");

	table.Print();

	//검색
	table.Print();
	Pair<std::string, std::string> outvalue;

	if (table.Find("SEH", outvalue.key))
		std::cout << "검색 성공. Key " << outvalue.key << " " << outvalue.value << "\n";

	table.Delete("MEE");
	table.Delete("HER")

	std::cin.get();
}