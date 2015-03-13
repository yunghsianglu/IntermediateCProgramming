// bottomup.c
#include <stdio.h>
#include <stdlib.h>
int func(int n)
{
  int * arr;
  // need n + 1 for arr[n]
  arr = malloc(sizeof(int) * (n + 1)); 
  arr[0] = 1;
  arr[1] = 1;
  int ind;
  for (ind = 2; ind <= n; ind ++)
    {
      arr[ind] = arr[ind - 1] + arr[ind / 2];
    }
  int val = arr[n];
  free (arr);
  return val;
}

int main(int argc, char * * argv)
{
  int val = 4;
  int fv = func(val);
  printf("f(%d) = %d\n", val, fv);
  return EXIT_SUCCESS;
}
