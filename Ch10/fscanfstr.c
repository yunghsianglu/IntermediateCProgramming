// fscanfstr.c
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 6
int main(int argc, char * argv[])
{
  FILE * fptr;
  if (argc < 2)
    {
      printf("Need to provide the file's name.\n");
      return EXIT_FAILURE;
    }
  fptr = fopen(argv[1], "r");
  if (fptr == NULL)
    {
      printf("fopen fail.\n");
      return EXIT_FAILURE;
    }
  char buffer[MAXSIZE];
  while (fscanf(fptr, "%5s", buffer) == 1)
    {
      printf("%s\n", buffer);
    }
  fclose(fptr);
  return EXIT_SUCCESS;
}
