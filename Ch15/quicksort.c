// quicksort.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define RANGE        10000
int * arrGen(int size);
// generate a sorted array of integers

void swap(int * a, int * b);

static void quickSortHelp(int * arr, int first, int last)
{
  // [first, last]: range of valid indexes (not last - 1)
  if (first >= last) // no need to sort one or no element 
    {
      return; 
    }
#ifdef DEBUG
  printf("first = %d, last = %d\n", first, last);
#endif 
  int pivot = arr[first];
  int low = first + 1;
  int high = last;
  while (low < high)
    {
      while ((low < last) && (arr[low] <= pivot))
	{
	  // <= so that low will increment when arr[low] 
	  // is the same as pivot,  using < will stop 
	  // incrementing low when arr[low] is the same 
	  // as pivot and the outer while loop will not stop
	  low ++;
	}
      while ((first < high) && (arr[high] > pivot))
	{
	  high --;
	}
      if (low < high)
	{
	  swap (& arr[low], & arr[high]);
	}
    }
  if (pivot > arr[high])
    {
      swap(& arr[first], & arr[high]);
    }
  quickSortHelp(arr, first, high - 1);
  quickSortHelp(arr, low, last);
}

void quickSort(int * arr, int len)
{
  quickSortHelp(arr, 0, len - 1);
}

void printArray(int * arr, int len);

int main(int argc, char * * argv)
{
  if (argc < 2)
    {
      printf("need a positive integer\n");
      return EXIT_FAILURE;
    }
  if (argc == 3)
    {
      srand(strtol(argv[2], NULL, 10));
    }
  else 
    {
      srand(time(NULL)); // set the seed
    }
  int num = strtol(argv[1], NULL, 10);
  if (num <= 0)
    {
      printf("need a positive integer\n");
      return EXIT_FAILURE;
    }
  int * arr = arrGen(num);
  printArray(arr, num);
  quickSort(arr, num);
  printArray(arr, num);
  free (arr);
  return EXIT_SUCCESS;
}

void swap(int * a, int * b)
{
  int s = * a;
  * a = * b;
  * b = s;
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
  int ind;
  for (ind = 0; ind < size; ind ++)
    {
      arr[ind] = rand() % RANGE;
    }  
  return arr;
}

void printArray(int * arr, int len)
{
  int ind;
  int sorted = 1;
  for (ind = 0; ind < len; ind ++)
    {
#ifdef DEBUG
      printf("%d ", arr[ind]);
#endif
      if ((ind > 0) && (arr[ind] < arr[ind -1]))
	{
	  sorted = 0;
	}
    }
  printf("\nsorted = %d\n\n", sorted);
}
