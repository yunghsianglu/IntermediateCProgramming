// testgen.c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define RANGE        10000 
int main(int argc, char * * argv)
{
  if (argc < 2)
    {
      printf("need a positive integer\n");
      return EXIT_FAILURE;
    }
  int num = strtol(argv[1], NULL, 10);
  if (num <= 0)
    {
      printf("need a positive integer\n");
      return EXIT_FAILURE;
    }
  srand(time(NULL)); // set the seed
  int count;
  for (count = 0; count < num; count ++)
    {
      printf("%d\n", rand() % RANGE);
    }
  return EXIT_SUCCESS;
}
