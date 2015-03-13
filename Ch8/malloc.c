// malloc.c
// create an array whose size is specified at run time.  
// The array's elements are the command line arguments.  
// The program adds the elements and prints the sum.
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  int * arr2;
  int iter;
  int sum = 0;
  if (argc < 2)
    {
      printf("Need to provide some integers.\n");
      return EXIT_FAILURE;
    }
  arr2 = malloc(argc * sizeof(int));
  if (arr2 == NULL)
    {
      printf("malloc fails.\n");
      return EXIT_FAILURE;
    }
  /* iter starts at 1 because argv[0] is the program's name */
  for (iter = 1; iter < argc; iter ++)
    {
      arr2[iter] = (int) strtol(argv[iter], NULL, 10);
    }
  printf("The sum of ");
  for (iter = 1; iter < argc; iter ++)
    {
      printf("%d ", arr2[iter]);
      sum += arr2[iter];
    }
  printf("is %d.\n", sum);
  
  free (arr2);
  return EXIT_SUCCESS;
}
