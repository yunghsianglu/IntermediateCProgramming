// countchar.c
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  FILE * fptr;
  int ch;
  int counter = 0;
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
  printf("The name of the file is %s.\n", argv[1]);
  do
    {
      ch = fgetc(fptr);
      if (ch != EOF)
	{
	  counter ++;
	}
    } while (ch != EOF);
  fclose(fptr);
  printf("The file has %d characters.\n", counter);
  return EXIT_SUCCESS;
}
