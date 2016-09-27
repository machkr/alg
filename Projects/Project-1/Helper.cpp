#include "Helper.hpp"
#include <stdlib.h>
#include <string.h>
using namespace std;

/**
  Creates a sorted array of size n

  @param n the size of the array
  @return the array
 */
int* sortedArray(int n)
{
  int* arr = new int[n];
  for (int i = 0; i < n; i++)
    arr[i] = i+1;
  return arr;
}

/**
  Creates an array of n zeros

  @param n the size of the array
  @return the array
 */
int* constArray(int n)
{
  int* arr = new int[n];
  memset(arr, 0, n*sizeof(int));
  return arr;
}

/**
  Creates a random permutation of the integers 1 to n

  @param n the size of the array
  @return the array
 */
int* randomArray(int n)
{
  int* arr = sortedArray(n);
  for (int i = n; i > 1; i--)
  {
    int swap = rand() % i;
    Swap(arr[swap], arr[i-1]);
  }

  return arr;
}
