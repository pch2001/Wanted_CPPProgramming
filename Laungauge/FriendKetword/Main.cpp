#include<iostream>

class Entity {
public:

	friend void ShowEntity(Entity& entity) {
		std::cout << entity.x << ", " << entity.y << "\n";

	}

private:
	int x = 0;
	int y = 0;

};

//Entity 정보를 출력하는 함수
//void ShowEntity(Entity& entity) {
//	std::cout << entity.x << ", " << entity.y << "\n";
//
//}

int main() {
	Entity entity;
	ShowEntity(entity);

	std::cin.get();
}