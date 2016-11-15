//###################################################//
//          Project 2 - Dynamic Programming          //
//  Junior Recinos, Lott Lalime, and Matthew Kramer  //
//         COT 4400 - Analysis of Algorithms         //
//###################################################//

#include <climits>
#include <cmath>
#include <cstdlib>		//Standard C++ Library
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void bestPartitions(vector<int> &array, int t, ofstream &outfile);

int main()
{
	int instances, // Number of problems, as read in from input file
		n, // Number of integers within data array
		t, // Maximum size of any partition
		temp; // Used in reading data from file

	// Open input file
	ifstream infile;
	infile.open("input.txt");

	// Error checking
	if ( !infile.is_open() )
	{
		cout << "Unable to open 'input.txt'." << endl;
		return 0;
	}

	// Open output file
	ofstream outfile;
	outfile.open("output.txt");
	
	// Error checking
	if ( !outfile.is_open() )
	{
		cout << "Unable to open 'output.txt'." << endl;
		return 0;
	}

	// Get number of problem instances
	infile >> instances;

	// Notify user of the number of problems to be solved
	cout << endl << instances << " instances defined." << endl;

	// Iterate over all problem instances
	for (int i = 0; i < instances; i++)
	{
		// Output current instance
		cout << endl << "Instance " << i + 1 << ":" << endl;
		
		// Get number of integers and threshold for problem instance
		infile >> n >> t;
		
		// Create new vector of integers for holding data array
		vector<int> array;

		// Get data array
		for (int j = 0; j < n; j++)
		{
			infile >> temp; // Store in temporary variable
			array.push_back(temp); // Push to the back of the vector
		}

		// Call optimize function on array vector
		bestPartitions(array, t, outfile);

		// Clear array when complete
		array.clear();
	}

	// Close file streams
	infile.close();
	outfile.close();

	// Notify user of successful program completion
	cout << endl << "Done. Output located in \"output.txt\"" << endl << endl;
}

// Algorithm isolated within this function
void bestPartitions(vector<int> &array, int t, ofstream &outfile)
{
	int table[array.size()][array.size()]; // Table for memoization
	vector<int> solution; // Vector for solution

	// Initialize two-dimensional array with maximum integer placeholders
	for ( int i = 0; i < array.size(); i++ )
	{
		for ( int j = 0; j < array.size(); j++ )
		{
			table[i][j] = INT_MAX;
		}
	}

	// Iterative approach
	for ( int i = 0; i < array.size(); i++ ) // Iterates through elements in array
	{
		int sum = 0; // Sum initially set to zero for each iteration

		for ( int j = i; j < array.size(); j++ ) // All elements from i to end of array
		{
			sum = sum + array[j]; // Add current element in array to sum

			if ( sum <= t ) // If this calculated sum is below the max partition size
			{
				int tmpmin = INT_MAX; // Create a temporary min value

				if ( i != 0 ) // If we are optimizing some sub-array of the array
				{
					for ( int k = 0; k < array.size(); k++ ) // Iterate over the array
					{
						if ( tmpmin > table[k][i - 1]) // Checking for minimum score value
						{
							tmpmin = table[k][i - 1]; // And assigning it to tmpmin
						}
					}
				}
				else // First iteration, when i == 0 (considering full array)
				{
					tmpmin = 0; // Score of elements not considered is 0
				}

				table[i][j] = pow(t - sum, 2) + tmpmin; // Stores total inequality score
			}
		}
	}

	// Initialize the instance minimum score
	int minscore = INT_MAX;

	// Find minimum total score in dynamic programming structure
	for (int i = 0; i < array.size(); i++ ) // Iterate over all rows of dynamic programming structure
	{
		if ( minscore > table[i][array.size() - 1] ) // If current minimum score is greater than value in last column
		{
			minscore = table[i][array.size() - 1]; // Set the current minimum score to this value
		}
	}

	// Output this problem instance's minimum inequality score
	cout << "Minimum Inequality Score: " << minscore << endl;
	
	int column = array.size() - 1; // For use in navigating table columns
	int row = 0; // For use in navigating table rows
	int count = 0; // Placeholder for number of partitions

	// Find number and size of partitions in optimized solution
	while ( column >= 0 )
	{
		int min = INT_MAX;

		// Iterates through the table updating the minimum value
		for ( int i = 0; i < array.size(); i++ )
		{
			// If the current min is greater than value currently being examined
			if ( min > table[i][column] )
			{
				min = table[i][column]; // Make this value the current min
				row = i; // Set row to column of current minimum value
			}
		}

		// Adds the solutions to the solution vector
		solution.push_back((column - row) + 1);

		// Increment the number of partitions
		count = count + 1;

		// And set the column to diagonals
		column = row - 1;
	}

	// Writes the number of partitions to the output file
	outfile << count << " ";

	// Writes the size of each partition to the output file
	while ( !solution.empty() )
	{
		outfile << solution.back() << " "; // Output last element in solution vector
		solution.pop_back(); // Pop last element in solution vector
	}

	outfile << endl; // End problem instance solution with a new line character
}
