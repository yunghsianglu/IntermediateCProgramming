// binarysearch.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE 100
int * arrGen(int size);
// generate a sorted array of integers

static int binarySearchHelp(int * arr, int low, 
			    int high, int key)
{
  if (low > high)
    {
      return -1;
    }
  int ind = (low + high) / 2;
  if (arr[ind] == key) 
    {
      return ind;
    }
  if (arr[ind] > key)
    {
      return binarySearchHelp(arr, low, ind - 1, key);
    }
  return binarySearchHelp(arr, ind + 1, high, key);
}

int binarySearch(int * arr, int len, int key)
{
  return binarySearchHelp(arr, 0, len - 1, key);
}

void printArray(int * arr, int len);

int main(int argc, char * * argv)
{
  if (argc < 2)
    {
      printf("need a positive integer\n");
      return EXIT_FAILURE;
    }
  int num = strtol(argv[1], NULL, 10);
  if (num <= 0)
    {
      printf("need a positive integer\n");
      return EXIT_FAILURE;
    }
  int * arr = arrGen(num);
  printArray(arr, num);
  int count;
  for (count = 0; count < 10; count ++)
    {
      int key; 
      if ((count % 2) == 0)
	{
	  key = arr[rand() % num];
	}
      else
	{
	  key = rand() % 100000;
	}
      printf("search(%d), result = %d\n", 
	     key, binarySearch(arr, num, key));
    }
  free (arr);
  return EXIT_SUCCESS;
}

int * arrGen(int size)
{
  if (size <= 0)
    {
      return NULL; 
    }
  int * arr = malloc(sizeof(int) * size);
  if (arr == NULL)
    {
      return NULL;
    }
  srand(time(NULL)); // set the seed
  int ind;
  arr[0] = rand() % RANGE;
  for (ind = 1; ind < size; ind ++)
    {
      arr[ind] = arr[ind - 1] + (rand() % RANGE) + 1;
    }  
  return arr;
}

void printArray(int * arr, int len)
{
  int ind;
  for (ind = 0; ind < len; ind ++)
    {
      printf("%d ", arr[ind]);
    }
  printf("\n\n");
}
