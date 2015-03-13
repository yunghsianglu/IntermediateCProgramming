// trace1.c
#include <stdio.h>
#include <stdlib.h>
int func(int n, int * count)
{
  (* count) ++; 
  if ((n == 0) || (n == 1))
    {
      return 1;
    }
  int val = 0;
  int a = func(n - 1, count);
  int b = func(n / 2, count);
  val += a + b;
  return val;
}
int main(int argc, char * * argv)
{
  int count = 0;
  int val = 4;
  int fv = func(val, & count);
  printf("f(%d) = %d, count = %d\n", val, fv, count);
  return EXIT_SUCCESS;
}
