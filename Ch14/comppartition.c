// comppartition.c
// partition using alternating odd and even numbers
// two ways to implement the partition:
// 1. check before recursive calls
// 2. generate all partitions and check before printing
#include <stdio.h>
#include <stdlib.h>
void printPartition(int * arr, int length)
{
  /*
  int ind;
  for (ind = 0; ind < length - 1; ind ++)
    {
      printf("%d + ", arr[ind]);
    }
  printf("%d\n", arr[length - 1]);
  */
}

// 1. generate only valid partitions
void partition1(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
    {
      printPartition(arr, ind);
      return;
    }
  for (val = 1; val <= left; val ++)
    {
      int valid = 0;
      if (ind == 0) // no restriction for the first number
	{
	  valid = 1;
	}
      else
	{
	  valid = (arr[ind - 1] % 2) != (val % 2);
	}
      if (valid == 1)
	{
	  arr[ind] = val;
	  partition1(arr, ind + 1, left - val);
	}
    }
}

// 2. before printing, check whether the partition is valid
// check whether the numbers are alternating odd and even
// return 1 if valid
// return 0 if invalid
int isValid(int * arr, int len) 
{
  if (len <= 1) // if only one number, it is valid
    {
      return 1;
    }
  int ind;
  for (ind = 2; ind < len; ind += 2)
    {

      // invalid if they are different
      if ((arr[ind] % 2) != (arr[0] % 2))
	{
	  return 0;
	}
    }
  for (ind = 1; ind < len; ind += 2)
    {

      // invalid if they are the same
      if ((arr[ind] % 2) == (arr[0] % 2))
	{
	  return 0;
	}
    }
  return 1;
}
// generate all possible partitions, including invalid
// check before printing
void partition2(int * arr, int ind, int left)
{
  int val;
  if (left == 0)
    {
      if (isValid(arr, ind) == 1)
	{
	  printPartition(arr, ind);
	}
      return;
    }
  for (val = 1; val <= left; val ++)
    {
      arr[ind] = val;
      partition2(arr, ind + 1, left - val);
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
  printf("-----Partition 1-----\n");
  partition1(arr, 0, n);
  printf("-----Partition 2-----\n");
  partition2(arr, 0, n);
  free (arr);
  return EXIT_SUCCESS;
}
