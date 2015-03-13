/*
 * main.c
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mysort.h"
int main(int argc, char * * argv)
{
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }
  int number = strtol(argv[1], NULL, 10);
  int * arr;
  arr = malloc(sizeof(int) * number);
  if (arr == NULL)
    {
      return EXIT_FAILURE;
    }
  int ind;
  for (ind = 0; ind < number; ind ++)
    {
      scanf("%d", & arr[ind]);
    }
  mysort(arr, number);
  for (ind = 0; ind < number; ind ++)
    {
      printf("%d\n", arr[ind]);
    }
  free (arr);
  return EXIT_SUCCESS;
}

