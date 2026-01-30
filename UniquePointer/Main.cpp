#include <iostream>
#include <memory>

class Player
{
public :
	Player()
	{
		std::cout << "생성자 호출 \n";
	}
	~Player()
	{
		std::cout << "소멸자 호출 \n";
	}
	
};

void Function(std::unique_ptr<Player> player)
{
	std::cout << "Player 받은\n";
}

void Function2(std::unique_ptr<Player>& player)
{
	std::cout << "Player 받은\n";
}

int main()
{

	//unique_ptr 객체 선언
	std::unique_ptr<Player> player = std::make_unique<Player>();
	//move생성자
	//std::unique_ptr<Player> player2 = std::move(player);
	
	Function(std::make_unique<Player>());
	Function2(player);


	//함수를 호출하면서 생성하는 부분에만 가능하다.


	std::cin.get();

}