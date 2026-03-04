#include <iostream>
#include <fstream>
#include <sstream>
#include <conio.h> // 방향키 입력
#include <string>

#include <windows.h>

#include "Container/Vector.h"

class Card
{
public :
	int id, cost, rarity;
	std::string name, type;
	void Print() const
	{
		std::cout << "[" << id << "] Name: " << name << "\n";
		std::cout << "Type: " << type << " | Cost: " << cost << " | Rarity: " << rarity << "\n";
	}
};

void LoadCards(Vector<Card>& cardPack)
{
	std::ifstream file("cards.csv");
	if (!file.is_open())
	{
		std::cout << " 파일 XXX " << "\n";
	}
	std::string line;
	std::getline(file, line);

	while (std::getline(file, line)) {
		std::stringstream ss(line);
		std::string temp;
		Card card;

		std::getline(ss, temp, ','); card.id = std::stoi(temp);
		std::getline(ss, card.name, ',');
		std::getline(ss, card.type, ',');
		std::getline(ss, temp, ','); card.cost = std::stoi(temp);
		std::getline(ss, temp, ','); card.rarity = std::stoi(temp);

		cardPack.PushBack(card);
	}
	file.close();

}
int main()
{
	Vector<Card> cardPack;
	LoadCards(cardPack);

	
	int currentIndex = 0;
	while (1)
	{
		std::cout << "현재 인덱스: " << currentIndex + 1 << " / " << cardPack.Size() << "\n";
		cardPack[currentIndex].Print();

		int key = _getch();
		if (key == 27) break;

		// 방향키 처리 (224 처리 추가)
		if (key == 224 || key == 0) {
			key = _getch();
			if (key == 77) { // 오른쪽
				currentIndex++;
				if (currentIndex >= cardPack.Size()) currentIndex = 0;
			}
			else if (key == 75) { // 왼쪽
				currentIndex--;
				if (currentIndex < 0) currentIndex = cardPack.Size() - 1;
			}
		}

		// 핵심: 꾹 누르고 있을 때 쌓인 키 입력 버퍼를 모두 비움
		while (_kbhit()) {
			_getch();
		}
	}
}