#include "Player.h"

//기본값 설정 , 자원 할당
Player::Player()
{
}

//자원 해제
Player::~Player()
{
}

void Player::Move(int inX, int inY) {
	x = inX;
	y = inY;
}