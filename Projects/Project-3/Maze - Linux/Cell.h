//######################################################//
//    PROJECT 3: Graph Modeling and Graph Algorithms    //
//          The Itsy-Bitsy Spider Maze Problem          //
//              Matthew Kramer [U20891900]              //
//           COP 4400: ANALYSIS OF ALGORITHMS           //
//######################################################//

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Cell
{
public:
	// State of the cell when exploring
	bool visited;

	// Pointers to adjacent cells
	Cell *north;
	Cell *east;
	Cell *south;
	Cell *west;
	Cell *up;
	Cell *down;

	// Location of cell within matrix
	int level;
	int row;
	int column;

	// Constructor/Destructor
	Cell();
	Cell(int _level, int _row, int _column);
	~Cell();

	// Check visited status
	bool isvisited();

	// Check visited status of all adjacent cells
	bool isexplored();
};
