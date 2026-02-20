#include "HashTable.h"

//해시 함수(Hash Function)
//키를 어떤한 과정을 통해서 숫자로 변환해주는 함수
//여기에 붙이는 static은 전역이 아니라 private의 의미
static int GenerateKey(const std::string& keyString)
{
	//출력할 해시 변수 선언
	int hash = 0;

	//문자열을 문자 배열로 활용해 해시 생성
	const int length = static_cast<int>(keyString.length());
	for (int ix = 0; ix < length; ++ix)
	{
		//해시 생성 로직
		// hash += keyString[ix] * (ix + 1);	//-> 선능이 좋지 않아 java에서 사용하는 로직 사용
		hash = hash * 31 + keyString[ix];		//Java의 방식 Hornor' method

	}

	return hash;
}

HashTable::HashTable()
{
}

HashTable::~HashTable()
{
}

void HashTable::Add(const std::string& key, const std::string* value)
{
	//
}

void HashTable::Delete(const std::string& key)
{
}

bool HashTable::Find(const std::string& key, Entry& outEntry)
{
	return false;
}


//출력 함수
void HashTable::Print()
{

}

//Getter.
bool HashTable::IsEmpty() const
{
	return true;
}
