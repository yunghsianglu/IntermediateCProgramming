/* hanoi1.c
 * calculate the number of moves needed to move n disks
 */
#include <stdio.h>
#include <stdlib.h>
int f(int n)
{
  /* Base case */
  if (n == 1) 
    {
      return 1;
    }
  /* Recursive case */
  return 2 * f(n - 1) + 1;
}

int main(int argc, char * argv[])
{
  int n;
  if (argc < 2)
    {
      printf("need one positive integer.\n");
      return EXIT_FAILURE;
    }
  n = (int) strtol(argv[1], NULL, 10);
  if (n <= 0)
    {
      printf("need one positive integer.\n");
      return EXIT_FAILURE;
    }
  printf("f(%d) = %d.\n", n, f(n));
  return EXIT_SUCCESS;
}
