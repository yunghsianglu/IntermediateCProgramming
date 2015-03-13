// mainfactorial.c
#include <stdio.h>
#include <stdlib.h>
#define MAXN 20
long int fac(int n);
int main(int argc, char * argv[])
{
  int nval;
  for (nval = 0; nval <= MAXN; nval ++)
    {
      long int fval = fac(nval);
      printf("fac(%2d) = %ld\n", nval, fval);
    }
  return EXIT_SUCCESS;
}
