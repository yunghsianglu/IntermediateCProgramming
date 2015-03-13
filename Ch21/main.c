// main.c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include "subsetsum.h"
int main (int argc, char *argv[])
{
  // read the data from a file 
  if (argc < 2)
    {
      printf("Need input file name\n");
      return EXIT_FAILURE;
    }
  FILE * fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("fopen fail\n");
      return EXIT_FAILURE;
    }
  int numInt = countInteger(fptr);
  // go back to the beginning of the file
  fseek (fptr, 0, SEEK_SET);
  int kval; // the value equal to the sum
  if (fscanf(fptr, "%d", & kval) != 1)
    {
      printf("fscanf error\n");
      fclose(fptr);
      return EXIT_FAILURE;
    }
  numInt --; // kval is not part of the set
  int * setA = malloc(sizeof(int) * numInt);
  int ind = 0;
  for (ind = 0; ind < numInt; ind ++)
    {
      int aval;
      if (fscanf(fptr, "%d", & aval) != 1)
	{
	  printf("fscanf error\n");
	  fclose(fptr);
	  return EXIT_FAILURE;
	}
      setA[ind] = aval;
    }
  fclose (fptr);
  if (isValidSet(setA, numInt) == 1)
    {
      printf("There are %d subsets whose sums are %d\n",
	     subsetSum(setA, numInt, kval), kval);
    }
  else
    {
      printf("Invalid set\n");
    }
  free(setA);
  return EXIT_SUCCESS;
}
