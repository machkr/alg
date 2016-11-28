#include "Cell.h"

Cell::Cell()
{
	visited = false;

	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
	up = nullptr;
	down = nullptr;

	level = -1;
	row = -1;
	column = -1;
}

Cell::Cell(int _level, int _row, int _column)
{
	visited = false;

	north = nullptr;
	east = nullptr;
	south = nullptr;
	west = nullptr;
	up = nullptr;
	down = nullptr;

	level = _level;
	row = _row;
	column = _column;
}

Cell::~Cell(){}

bool Cell::isvisited()
{
	return this->visited;
}

bool Cell::isexplored()
{
	if (this->north->isvisited() || this->north == nullptr)
	{
		if (this->east->isvisited() || this->east == nullptr)
		{
			if (this->south->isvisited() || this->south == nullptr)
			{
				if (this->west->isvisited() || this->west == nullptr)
				{
					if (this->up->isvisited() || this->up == nullptr)
					{
						if (this->down->isvisited() || this->down == nullptr)
						{
							return true;
						}
						return false;
					}
					return false;
				}
				return false;
			}
			return false;
		}
		return false;
	}
	return false;
}
