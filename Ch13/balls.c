/* 
 * balls.c
 * f(1) = 2
 * f(2) = 3
 * f(n) = f(n-1) + f(n-2)
 */
#include <stdio.h>
#include <stdlib.h>
int f(int m) 
// use m instead of n to distinguish m in f and n in main
{
  /* Base cases */
  if (m <= 0)
    {
      printf("Invalid Number %d, must be positive.\n", m);
      return -1;
    }
  if (m == 1)
    {
      return 2; // f(1) = 2
    }
  if (m == 2)
    {
      return 3; // f(2) = 3
    }   
  /* Recursive case */ 
  int a;
  int b;
  a = f(m - 1);
  b = f(m - 2);
  return (a + b);
}

int main(int argc, char * argv[])
{
  int c;
  int n;
  if (argc < 2)
    {
      printf("need 1 integer.\n");
      return EXIT_FAILURE;
    }
  n = (int) strtol(argv[1], NULL, 10);
  c = f(n);
  printf("f(%d) = %d.\n", n, c);
  return EXIT_SUCCESS;
}
