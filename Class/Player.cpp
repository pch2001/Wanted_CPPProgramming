#include "Player.h"
#include <iostream>
//기본값 설정 , 자원 할당
Player::Player()
{

}

//자원 해제
Player::~Player()
{
	if (name != nullptr) {
		delete[] name;
		name = nullptr;
	}

}
Player::Player(const char* inName) {
	//동적 할당 및 문자열 복사
	size_t length = strlen(inName) + 1;
	name = new char[length];

	//복사처리
	strcpy_s(name, length, inName);

}

void Player::Move(int inX, int inY) {
	x = inX;
	y = inY;
}