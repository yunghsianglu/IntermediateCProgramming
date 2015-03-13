// searchbug.c
#include <stdio.h>
#include <stdlib.h>
int binarySearch(int * arr, int key, int len);
#define ARRAYSIZE 10
int main(int argc, char * * argv)
{
  int arr[ARRAYSIZE] = {1, 12, 23, 44, 65, 
			76, 77, 98, 109, 110};
  int ind;
  for (ind = 0; ind < ARRAYSIZE; ind ++)
    {
      printf("%d\n", binarySearch(arr, arr[ind], 
				  ARRAYSIZE));
    }
  return EXIT_SUCCESS;
}

int binarySearchHelp(int * arr, int key, int low, int high)
{
  if (low >= high) /* ERROR: should be >, not >= */
    {
      return -1; 
    }
  int mid = (low + high) / 2;
  if (arr[mid] == key)
    {
      return mid;
    }
  if (arr[mid] > key)
    {
      return binarySearchHelp(arr, key, low, mid - 1);
    }
  return binarySearchHelp(arr, key, mid + 1, high);
}

int binarySearch(int * arr, int key, int len)
{
  return binarySearchHelp(arr, key, 0, len - 1);
}


