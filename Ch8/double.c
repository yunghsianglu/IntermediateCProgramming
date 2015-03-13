// double.c
#include <stdio.h>
#include <stdlib.h>
void multi2(int * array, int length)
{
  int iter;
  for (iter = 0; iter < length; iter ++)
    {
      array[iter] *= 2;
    }
}
int main(int argc, char * argv[])
{
  int * arr;
  int iter;
  int length = 12;
  arr = malloc(length * sizeof(int));
  if (arr == NULL)
    {
      printf("malloc fails.\n");
      return EXIT_FAILURE;
    }
  for (iter = 0; iter < length; iter ++)
    {
      arr[iter] = iter;
    }
  
  printf("Original array: ");
  for (iter = 0; iter < length; iter ++)
    {
      printf("%2d ", arr[iter]);
    }
  printf("\n");

  multi2(arr, length);

  printf("New array:      ");
  for (iter = 0; iter < length; iter ++)
    {
      printf("%2d ", arr[iter]);
    }
  printf("\n");

  free (arr);
  return EXIT_SUCCESS;
}
