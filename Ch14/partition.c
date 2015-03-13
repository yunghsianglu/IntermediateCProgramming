// partition.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printPartition(int * arr, int length)
{
  int ind;
  for (ind = 0; ind < length - 1; ind ++)
    {
      printf("%d + ", arr[ind]);
    }
  printf("%d\n", arr[length - 1]);
}

void partition(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
    {
      printPartition(arr, ind);
      return; // not necessary
    }
  for (val = 1; val <= left; val ++)
    {
      arr[ind] = val;
      partition(arr, ind + 1, left - val);
    }
}

int main(int argc, char * argv[])
{
  if (argc != 2) 
    {
      return EXIT_FAILURE;
    }
  int n = (int) strtol(argv[1], NULL, 10);
  if (n <= 0) 
    {
      return EXIT_FAILURE;      
    }
  int * arr;
  arr = malloc(sizeof(int) * n);
  partition(arr, 0, n);
  free (arr);
  return EXIT_SUCCESS;
}
