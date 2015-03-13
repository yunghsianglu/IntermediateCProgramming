// combine.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void printArray(int * arr, int length)
{
  int ind;
  for (ind = 0; ind < length; ind ++)
    {
      if (arr[ind] == 1)
	{
	  printf("%c ", ind + 'A');
	}
    }
  printf("\n");
}

void combineHelp(int * arr, int ind, int num, 
		 int sel, int sum)
{
  if (sum == sel) // select enough items
    {
      printArray(arr, num);
      return;
     }
  if (ind == num) // end of array, no more item to select
    {
      return; 
    }
  // select this element
  arr[ind] = 1; 
  combineHelp(arr, ind + 1, num, sel, sum + 1);
  // do not select this element
  arr[ind] = 0; 
  combineHelp(arr, ind + 1, num, sel, sum);
}

void combine(int * arr, int num, int sel)
{
  combineHelp(arr, 0, num, sel, 0);
}

int main(int argc, char * argv[])
{
  if (argc != 3) // need two numbers
    {
      return EXIT_FAILURE;
    }
  int num = (int) strtol(argv[1], NULL, 10);
  if (num <= 0) 
    {
      return EXIT_FAILURE;      
    }
  int sel = (int) strtol(argv[2], NULL, 10);
  if ((sel <= 0) || (sel > num))
    {
      return EXIT_FAILURE;      
    }
  int * arr;
  arr = malloc(sizeof(int) * num);
  int ind;
  for (ind = 0; ind < num; ind ++)
    {
      arr[ind] = 0;
    }
  combine(arr, num, sel);
  free (arr);
  return EXIT_SUCCESS;
}
