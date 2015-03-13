// testgen.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// command line arguments
//    argv[1]: the number of elements
//            must be between 3 and 31
//    argv[2]: "1" the array is valid
//             "0" the array is invalid
//    argv[3]: "1" if there is a solution
//             "0" if there is no solution
void swap(int * a, int * b)
{
  int t = * a;
  * a = * b;
  * b = t;
}
void shuffleArray(int * arr, int num)
{
  int ind1, ind2, ind3;
  for (ind1 = 0; ind1 < 1000; ind1 ++)
    {
      ind2 = rand() % num;
      ind3 = rand() % num;
      swap(& arr[ind2], & arr[ind3]);
    }
}

void printArray(int * arr, int num, int kval)
{
  printf("%d\n", kval);
  int ind;
  for (ind = 0; ind < num; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
}

int main(int argc, char ** argv)
{
  if (argc < 4)
    {
      return EXIT_FAILURE;
    }
  int numInt  = (int) strtol(argv[1], NULL, 10);
  int isValid = (int) strtol(argv[2], NULL, 10);
  int hasSol  = (int) strtol(argv[3], NULL, 10);
  if ((numInt < 3) || (numInt > 31))
    {
      return EXIT_FAILURE;
    }
  if ((hasSol != 0) && (hasSol != 1))
    {
      return EXIT_FAILURE;
    }
  if ((hasSol != 0) && (hasSol != 1))
    {
      return EXIT_FAILURE;
    }
  srand(time(NULL)); // set the seed
  int kval = 0;
  int * arr = malloc(sizeof(int) * numInt);
  int ind;
  // the array is increasing and all elements are distinct
  arr[0] = rand() % 100;
  for (ind = 1; ind < numInt; ind ++)
    {
      arr[ind] = arr[ind - 1] + (rand() % 10000) + 1;
    }
  if (isValid == 0)
    {
      if ((rand() % 2) == 0)
	{
	  // make two elements the same
	  arr[numInt - 1] = arr[0];
	}
      else
	{
	  // make an element negative or zero
	  arr[0] = - (rand() % 10000);
	}
      // kval irrelevant when the array is invalid
      kval = rand() % 10000 + 1;
    }
  else
    {
      for (ind = 0; ind < numInt; ind ++)
	{
	  if (hasSol == 0)
	    {
	      // kval > sum of all elements
	      kval += arr[ind] + 1;
	    }
	  else
	    {
	      if ((rand() % 3) == 1)
		{
		  kval += arr[ind];
		}
	    }
	}
      if (kval == 0) // only if hasSol is 1
	{
	  kval = arr[0];
	}
    }
  shuffleArray(arr, numInt);
  printArray(arr, numInt, kval);
  free(arr);
  return EXIT_SUCCESS;
}
