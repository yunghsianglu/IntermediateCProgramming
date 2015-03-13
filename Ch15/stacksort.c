// stacksort.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int findIndex(int * arr, int first, int last, int maxmin)
// find the index of the largest or smallest element
// the range is expressed by the indexes [first, last]
// maxmin = 1: find largest, maxmin = 0: find smallest
{
  int ind;
  int  answer = first;
  for (ind = first + 1; ind <= last; ind ++)
    {
      if (((maxmin == 1) && (arr[answer] < arr[ind])) ||
	  ((maxmin == 0) && (arr[answer] > arr[ind])))
	{
	  answer = ind;
	}
    }
  return answer;
}

int findMaxIndex(int * arr, int first, int last)
{
  return findIndex(arr, first, last, 1);
}

int findMinIndex(int * arr, int first, int last)
{
  return findIndex(arr, first, last, 0);
}

int isStackSortable(int * arr, int first, int last)
// check whether the range of the array is sortable
// return 1 if the range of the array is sortable
// return 0 if the range of the array is not sortable
{
  if (first >= last) // no or one element is stack sortable
    {
      return 1;
    }
  int maxIndex = findMaxIndex(arr, first, last);
  // consider the four cases
  // both A and B are empty
  // The array has only one element, it is stack sortable
  // already checked earlier

  // A is empty, B is not empty
  // check whether B is stack sortable
  if (first == maxIndex)
    {
      return isStackSortable(arr, first + 1, last);
    }
  // A is not empty, B is empty
  // check whether A is stack sortable
  if (maxIndex == last)
    {
      return isStackSortable(arr, first, last - 1);
    }
  // neither is empty
  int maxAIndex = findMaxIndex(arr, first, maxIndex - 1);
  int minBIndex = findMinIndex(arr, maxIndex + 1, last);
  if (arr[maxAIndex] > arr[minBIndex])
    {
      return 0; // not stack sortable
    }
  int sortA = isStackSortable(arr, first, maxIndex - 1);
  int sortB = isStackSortable(arr, maxIndex + 1, last);
  return (sortA && sortB); // return 1 only if both are 1
}

void printArray(int * arr, int length)
{
  if (isStackSortable(arr, 0, length - 1) == 0)
    {
      return;
    }
  int ind;
  for (ind = 0; ind < length - 1; ind ++)
    {
      printf("%d", arr[ind]);
    }
  printf("%d\n", arr[length - 1]);
}

void swap(int * a, int * b)
{
  int s = * a;
  * a = * b;
  * b = s;
}

void permuteHelp(int * arr, int ind, int num)
{
  if (ind == num)
    {
      printArray(arr, ind);
      return;
    }
  int loc; // destination of arr[ind]
  for (loc = ind; loc < num; loc ++)
    {
      swap(& arr[ind], & arr[loc]);
      permuteHelp(arr, ind + 1, num);
      swap(& arr[ind], & arr[loc]); // swap back
    }
}

void permute(int * arr, int num)
{
  permuteHelp(arr, 0, num);
}

int main(int argc, char * argv[])
{
  if (argc != 2) 
    {
      return EXIT_FAILURE;
    }
  int num = (int) strtol(argv[1], NULL, 10);
  if (num <= 0) 
    {
      return EXIT_FAILURE;      
    }
  int * arr;
  arr = malloc(sizeof(int) * num);
  int ind;
  for (ind = 0; ind < num; ind ++)
    {
      arr[ind] = ind + 1;
    }
  permute(arr, num);
  free (arr);
  return EXIT_SUCCESS;
}
