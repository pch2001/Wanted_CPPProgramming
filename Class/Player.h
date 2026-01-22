#pragma once //-> 중복 include 방지 구문(컴팡이러 구문)


class Player {

	// 접근 한정자/접근 제한자
	// 클래스 내부의 속성을 어디까지 노출시킬지 결정

public:
	Player();
	~Player() = default;
	
	void Move(int inX, int inY);

private:
	int x = 0;
	int y = 0;
	int speed = 0;
};
