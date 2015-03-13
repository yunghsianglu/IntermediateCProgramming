// factorial2.c
#include <stdio.h>
long int fac2(int n)
{
  if (n < 0)
    {
      printf("n cannot be negative\n");
      return 0;
    }
  if (n == 0)
    {
      return 1;
    }
  long int result = 1;
  while (n > 0)
    {
      result *= n;
      n --;
    }
  return result;
}
