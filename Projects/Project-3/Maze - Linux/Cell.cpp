//######################################################//
//    PROJECT 3: Graph Modeling and Graph Algorithms    //
//          The Itsy-Bitsy Spider Maze Problem          //
//              Matthew Kramer [U20891900]              //
//           COP 4400: ANALYSIS OF ALGORITHMS           //
//######################################################//

#include "Cell.h"

// Default constructor
Cell::Cell()
{
	// Unvisited
	visited = false;

	// Adjacent cells point to NULL
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	up = NULL;
	down = NULL;

	// Invalid coordinates
	level = -1;
	row = -1;
	column = -1;
}

// Constructor with coordinates as arguments
Cell::Cell(int _level, int _row, int _column)
{
	// Unvisited
	visited = false;

	// Adjacent cells point to NULL
	north = NULL;
	east = NULL;
	south = NULL;
	west = NULL;
	up = NULL;
	down = NULL;

	// Invalid coordinates
	level = _level;
	row = _row;
	column = _column;
}

// Destructor
Cell::~Cell(){}

bool Cell::isvisited()
{
	return this->visited;
}

bool Cell::isexplored()
{
	if (this->north->isvisited() || this->north == NULL)
	{
		if (this->east->isvisited() || this->east == NULL)
		{
			if (this->south->isvisited() || this->south == NULL)
			{
				if (this->west->isvisited() || this->west == NULL)
				{
					if (this->up->isvisited() || this->up == NULL)
					{
						if (this->down->isvisited() || this->down == NULL)
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
