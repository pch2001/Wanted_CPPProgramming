#include "Queue.h"
#include <iostream>

class Location2D
{
public : 
	Location2D() : row(0), col(0) {}
	Location2D(int x, int y) : row(x), col(y) {}

public :
	size_t row;
	size_t col;
};

const size_t MAZE_SIZE = 6;
char map[MAZE_SIZE][MAZE_SIZE] =
{
	{'1','1','1','1','1','1'},
	{'e','0','1','0','0','1'},
	{'1','0','0','0','1','1'},
	{'1','0','1','0','1','1'},
	{'1','0','1','0','0','x'},
	{'1','1','1','1','1','1'}
};

bool IsValidLocation(size_t row, size_t col)
{
	if (row > MAZE_SIZE || col >= MAZE_SIZE)
		return false;

	return map[row][col] == '0' || map[row][col] == 'x';
}

Location2D FindStartLocation()
{
	for (size_t ix = 0; ix < MAZE_SIZE; ++ix)
	{
		for(size_t iy = 0; iy < MAZE_SIZE; ++iy)
		{
			if (map[ix][iy] == 'e')
				return Location2D(ix, iy);
		}
	}

	return Location2D(0, 0);
}

void PrintMap()
{
	for (size_t ix = 0; ix < MAZE_SIZE; ++ix)
	{
		for (size_t iy = 0; iy < MAZE_SIZE; ++iy)
		{
			std::cout << map[ix][iy] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";

}

int main()
{
	Queue<Location2D, 100> locationQueue;
	locationQueue.Enqueue(FindStartLocation());

	PrintMap();

	size_t Ncount = 0;
	while (!locationQueue.IsEmpty())
	{
		Location2D newLocation = locationQueue.Dequeue();

		size_t newrow = newLocation.row;
		size_t newcol = newLocation.col;

		std::cout << "(" << newrow << ", " << newcol << ")";
		Ncount++;
		if (Ncount == 10)
		{
			Ncount = 0;
			std::cout << "\n";
		}
		if(map[newrow][newcol] == 'x')
		{
			std::cout << "길찾기 성공" << std::endl;
			PrintMap();

			return 0;
		}

		map[newrow][newcol] = '.';
		if (IsValidLocation(newrow - 1, newcol) == true)
		{
			locationQueue.Enqueue(Location2D(newrow - 1, newcol));
		}
		if (IsValidLocation(newrow + 1, newcol) == true)
		{
			locationQueue.Enqueue(Location2D(newrow + 1, newcol));
		}
		if (IsValidLocation(newrow, newcol - 1) == true)
		{
			locationQueue.Enqueue(Location2D(newrow, newcol - 1));
		}
		if (IsValidLocation(newrow, newcol + 1) == true)
		{
			locationQueue.Enqueue(Location2D(newrow, newcol + 1));
		}
	}
	std::cout << " \n미로 탐색 실패\n";



}