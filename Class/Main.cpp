#include <iostream>
#include "Player.h"


int main() {
	//인스턴스
	Player player1;


	Player* player2 = new Player();
	player2->Move(3, 10);
	delete player2;
	player2 = nullptr;

	std::cin.get();


}