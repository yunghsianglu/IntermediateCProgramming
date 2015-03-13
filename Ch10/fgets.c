// fgets.c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_LINE_LENGTH 81
// assume that the maximum length of each line is already know
int main(int argc, char * argv[])
{
  FILE * fptr;
  int numLine = 0; // must initialize to zero
  char oneLine[MAX_LINE_LENGTH];
  if (argc < 2)
    // must check argc before using argv[1]
    {
      printf("Need to provide the file's name.\n");
      return EXIT_FAILURE;
    }
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("fopen fail.\n");
      // do not call fclose (fptr) here
      return EXIT_FAILURE;
    }
  printf("The name of the file is %s.\n", argv[1]);
  while (fgets(oneLine, MAX_LINE_LENGTH, fptr) != NULL)
    {
      numLine ++;
    } 
  fclose(fptr);
  printf("The file has %d lines.\n", numLine);
  return EXIT_SUCCESS;
}
