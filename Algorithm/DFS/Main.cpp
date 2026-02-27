#include <stack>
#include <iostream>
#include <vector>
#include <Windows.h>

struct Location2D
{
	Location2D(int row = 0, int col = 0) : row(row), col(col){}

	int row;
	int col;
};

// 맵 배열.
int mapSize = 0;
std::vector<std::vector<char>> map
{
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

bool IsValidLocation(int row, int col)
{


	if (row < 0 || row >= mapSize || col < 0 || col >= mapSize)
		return false;
	return map[row][col] == '0' || map[row][col] == 'x';
}

void FindStartLocaiton(int& row, int& col)
{
	for (int ix = 0; ix < mapSize; ++ix)
	{
		for (int jx = 0; jx < mapSize; ++jx)
		{
			// 맵 출력.
			std::cout << map[ix][jx] << " ";

			// 시작 지점을 나타내는 문자 검색.
			if (map[ix][jx] == 'e')
			{
				row = ix;
				col = jx;
			}
		}
		std::cout << "\n";
	}
}


void EscapeMaze()
{
	mapSize = (int)map.size();
	int row = 0;
	int col = 0;

	FindStartLocaiton(row, col);
	std::stack<Location2D> stack;
	stack.push(Location2D(row, col));

	while (!stack.empty())
	{
		Location2D current = stack.top();
		stack.pop();
		std::cout << "(" << current.row << "," << current.col << ") ";

		row = current.row;
		col = current.col;

		if (map[row][col] == 'x')
		{
			std::cout << "\n미로 탈출 성공\n";
			return;
		}
		map[row][col] = '.';

		if (IsValidLocation(current.row - 1, current.col))
			stack.push(Location2D(current.row - 1, current.col));
		if (IsValidLocation(current.row + 1, current.col))
			stack.push(Location2D(current.row + 1, current.col));
		if (IsValidLocation(current.row , current.col-1))
			stack.push(Location2D(current.row , current.col-1));
		if (IsValidLocation(current.row , current.col+1))
			stack.push(Location2D(current.row , current.col+1));
	}
	std::cout << " \n미로 탐색 실패\n";

}


int main()
{

		EscapeMaze();
		Sleep(1000);


	std::cin.get();
}