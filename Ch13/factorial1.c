// factorial1.c
#include <stdio.h>
long int fac(int n)
{
  if (n < 0)
    {
      printf("n cannot be negative\n");
      return 0;
    }
  /* Base case */
  if (n == 0)
    {
      return 1;
    }
  /* Recursive case */
  return n * fac(n - 1);
}
