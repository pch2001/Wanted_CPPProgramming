#include <iostream>


class Entity {
public :
	Entity() {
		std::cout << "CIbstructor called\n";
	}
	~Entity() = default;


	//함수 끝에 const를 지정하면,
	//함수 본문에서 객체 내부의 값을 변경할 수 없음
	void showName() const{
		std::cout << "Entity\n";
	}

	const Entity* GetSelf() const{
		return this;
	}
};

int main() {

	/*Entity* entity = nullptr;
	entity->showName();
	showName(entity);*/

	/*const int count = 5;
	Entity entities[count]; 

	for (const Entity& entity : entities) {
		entity.showName();
	}*/


	/*const int count = 5;
	Entity* entities[count] = {};
	memset(entities, 0, sizeof(Entity*) * count);

	for (int ix = 0; ix < count; ++ix) {
		entities[ix] = new Entity();
	}

	for (Entity* entity : entities) {
		delete entity;
		entity = nullptr;
	}*/


	Entity* entity = new Entity();
	std::cout << entity << "\n";
	std::cout << entity->GetSelf() << "\n";
	delete entity;

	std::cin.get();


}