//######################################################//
//    PROJECT 3: Graph Modeling and Graph Algorithms    //
//          The Itsy-Bitsy Spider Maze Problem          //
//              Matthew Kramer [U20891900]              //
//           COP 4400: ANALYSIS OF ALGORITHMS           //
//######################################################//

#include "Cell.h"

using namespace std;

bool explore(Cell *current, Cell *end, vector<string> *route);

int main()
{
	int instances,	// Number of mazes in the input file
		levels,		// Number of levels in the maze instance
		rows,		// Number of rows in the maze instance
		columns,	// Number of columns in the maze instance
		ltemp,		// Temporary level variable
		rtemp,		// Temporary row variable
		ctemp;		// Temporary column variable

	char temp;		// Temporary character for file input

	vector<string> *route = new vector<string>();	// Pointer to vector for solution
	vector<int> array;								// Vector for storing directional bits

	// Declare file input stream and open input file
	ifstream infile;
	infile.open("input.txt");

	// Error checking
	if (!infile.is_open())
	{
		cout << "Unable to open 'input.txt'." << endl;
		return 0;
	}

	// Read in the number of maze instances
	infile >> instances;

	// Notify user of the number of the mazes defined
	cout << endl << instances << " maze instances defined." << endl;

	// Declare file output stream and open output file
	ofstream outfile;
	outfile.open("output.txt");

	// Error checking
	if (!outfile.is_open())
	{
		cout << "Unable to open 'output.txt'." << endl;
		return 0;
	}

	// Iterate over all maze instances
	for (int i = 0; i < instances; i++)
	{
		// Output the current maze being processed
		cout << endl << "Maze #" << i + 1 << ":" << endl;

		// Read in the number of levels, rows, and columns
		infile >> levels >> rows >> columns;
		cout << levels << " levels, " << rows << " rows, and " << columns << " columns." << endl;

		// Initialize a 3D-array of pointers to cells
		Cell ****matrix = new Cell***[levels];
		for (int i = 0; i < levels; i++)
		{
			matrix[i] = new Cell**[rows];
			for (int j = 0; j < rows; j++)
			{
				matrix[i][j] = new Cell*[columns];
				for (int k = 0; k < columns; k++)
				{
					Cell *cell = new Cell(i, j, k);
					matrix[i][j][k] = cell;
				}
			}
		}

		// Read in the level, row, and column of the starting point
		infile >> ltemp >> rtemp >> ctemp;

		// Declare a new cell pointer that points to this start point
		Cell *start;
		start = matrix[ltemp][rtemp][ctemp];
		cout << "Starting at (" << ltemp << ", " << rtemp << ", " << ctemp << ")";

		// Read in the level, row, and column of the ending point
		infile >> ltemp >> rtemp >> ctemp;

		// Declare a new cell pointer that points to this end point
		Cell *end;
		end = matrix[ltemp][rtemp][ctemp];
		cout << endl << "Ending at (" << ltemp << ", " << rtemp << ", " << ctemp << ")" << endl;

		// Iterate over the matrix, constructing the graph's edges
		for (int z = 0; z < levels; z++)
		{
			for (int y = 0; y < rows; y++)
			{
				for (int x = 0; x < columns; x++)
				{
					// Read in 6-bit directional information
					while (infile.good())
					{
						infile.get(temp);						// Get a character
						if (temp == ' ') break;					// Terminate at space
						if (temp == '\n') continue;				// Skip new-line characters
						if (temp == '0') array.push_back(0);	// Push 0 to vector
						if (temp == '1') array.push_back(1);	// Push 1 to vector
					}

					if (array[0]) // If there's a neighbor to the north
					{
						// Point the current cell's north pointer to its northern neighbor
						matrix[z][y][x]->north = matrix[z][y - 1][x];
					}

					if (array[1]) // If there's a neighbor to the east
					{
						// Point the current cell's east pointer to its eastern neighbor
						matrix[z][y][x]->east = matrix[z][y][x + 1];
					}

					if (array[2]) // If there's a neighbor to the south
					{
						// Point the current cell's south pointer to its southern neighbor
						matrix[z][y][x]->south = matrix[z][y + 1][x];
					}

					if (array[3]) // If there's a neighbor to the west
					{
						// Point the current cell's west pointer to its western neighbor
						matrix[z][y][x]->west = matrix[z][y][x - 1];
					}
 
					if (array[4]) // If there's a neighbor above
					{
						// Point the current cell's up pointer to its neighbor above
						matrix[z][y][x]->up = matrix[z + 1][y][x];
					}

					if (array[5]) // If there's a neighbor below
					{
						// Point the current cell's down pointer to its neighbor below
						matrix[z][y][x]->down = matrix[z - 1][y][x];
					}

					array.clear(); // Clear temporary input vector
				}
			}
		}

		// If the explore method returns true (route found)
		if (explore(start, end, route))
		{
			// Output how many steps it took
			cout << "Solved in " << route->size() << " steps." << endl;

			// Output the solution route to the file
			for (unsigned int i = 0; i < route->size(); i++)
			{
				outfile << (*route)[i];
				if (i != route->size() - 1) outfile << " ";
			}

			route->clear(); // Clear the solution vector
			outfile << endl; // Add a newline character
		}
		else
		{
			outfile << endl; // Add a newline character
			cout << "Maze could not be solved." << endl;
		}

		// Delete the matrix for this maze instance
		for (int i = 0; i < levels; i++)
		{
			for (int j = 0; j < rows; j++)
			{
				for (int k = 0; k < columns; k++)
				{
					delete matrix[i][j][k]; // Deleting cells
				}
				delete[] matrix[i][j]; // Deleting columns
			}
			delete[] matrix[i]; // Deleting rows
		}
		delete[] matrix; // Deleting levels
	}

	// Close input/output files
	infile.close();
	outfile.close();

	// Output spider to terminal
	cout << "\n  / _ \\\n\\_\\(_)/_/\n _//\"\\\\_\n  /   \\\n\n";
}

bool explore(Cell *current, Cell *end, vector<string> *route)
{ 
	if (current == end) // If the end has been reached
	{
		current->visited = true; // Mark the node as visited
		return true;
	}
	
	if (current == NULL || current->isvisited()) // If the current cell doesn't exist
	{
		if (!route->empty()) route->pop_back(); // Remove the last direction in the route
		return false;
	}

	current->visited = true; // Mark current cell as visited

	if (current->north != NULL) // If there exists a cell north of current
	{
		if (explore(current->north, end, route)) // Explore that candidate
		{
			route->insert(route->begin(), "N"); // Add its direction to the solution vector
			return true;
		}
	}

	if (current->east != NULL) // If there exists a cell east of current
	{
		if (explore((current->east), end, route)) // Explore that candidate
		{
			route->insert(route->begin(), "E"); // Add its direction to the solution vector
			return true;
		}
	}

	if (current->south != NULL) // If there exists a cell south of current
	{
		if (explore(current->south, end, route)) // Explore that candidate
		{
			route->insert(route->begin(), "S"); // Add its direction to the solution vector
			return true;
		}
	}

	if (current->west != NULL) // If there exists a cell west of current
	{
		if (explore(current->west, end, route)) // Explore that candidate
		{
			route->insert(route->begin(), "W"); // Add its direction to the solution vector
			return true;
		}
	}

	if (current->up != NULL) // If there exists a cell above current
	{
		if (explore(current->up, end, route)) // Explore that candidate
		{
			route->insert(route->begin(), "U"); // Add its direction to the solution vector
			return true;
		}
	}

	if (current->down != NULL) // If there exists a cell below current
	{
		if (explore(current->down, end, route)) // Explore that candidate
		{
			route->insert(route->begin(), "D"); // Add its direction to the solution vector
			return true;
		}
	}

	// If all else fails, return false
	return false;
}
