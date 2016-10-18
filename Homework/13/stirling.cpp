/**********************************************
	PROGRAM: stirling.cpp
	COURSE: Analysis of Algorithms
	AUTHOR: Matthew Kramer
	ASSIGNMENT: Homework 13
	PURPOSE: Compute the number of ways to
	divide n objects into k nonempty piles.
**********************************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	// Check for valid number of command line arguments
	if (argc != 3)
	{
		cout << endl << "USAGE: " << argv[0] << " <n> <k>" << endl << endl;
		exit(1);
	}

	// Variable declarations and argument conversions
	int n = atoi(argv[1]);
	int k = atoi(argv[2]);

	// Check for valid parameters considering the algorithm
	if(n < k)
	{
		cout << endl << "ERROR: invalid arguments [n < k]" << endl << endl;
		exit(1);
	}

	// Declare a two-dimensional array with k rows and n columns
	int arr[k][n];

	// Formatting
	cout << endl;

	// Iterate over rows
	for(int row = 0; row < k; row++) 
	{
		// Iterate over columns
		for(int col = 0; col < n; col++) 
		{
			// Base Case (k == 1 or k == n)
			if(row == 0 || row == col) arr[row][col] = 1;

			// Undefined Case (k > n)
			else if(row > col) arr[row][col] = 0;

			// Iterative case 
			else arr[row][col] = ((row + 1) * arr[row][col - 1]) + arr[row - 1][col - 1];

			// Print current array value for table
			cout << arr[row][col] << "\t"; 
		}

		// Formatting
		cout << endl << endl; 
	}

	// Output final result
	cout << "S(n, k) = S(" << n << ", " << k << ") = " << arr[k - 1][n - 1] << endl << endl;
}
