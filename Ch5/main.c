// main.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int areDistinct(int * arr, int len);
int main(int argc, char * * argv)
{
  if (argc != 2)
    {
      return EXIT_FAILURE;
    }
  FILE * fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      return EXIT_FAILURE;
    }
  int length = 0;
  int value;
  while (fscanf(fptr, "%d", & value) == 1)
    {
      length ++;
    }
  fseek (fptr, 0, SEEK_SET);
  int * arr = malloc(length * sizeof(int));
  length = 0;
  while (fscanf(fptr, "%d", & (arr[length])) == 1)
    {
      length ++;
    }
  fclose (fptr);
  int dist = areDistinct(arr, length);
  printf("The elements are");
  if (dist == 0)
    {
      printf(" not");
    }
  printf(" distinct.\n");
  free (arr);
  return EXIT_SUCCESS;
}

