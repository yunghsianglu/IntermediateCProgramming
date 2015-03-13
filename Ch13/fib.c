// fib.c
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#define MAXN 20
#define REPEAT 100000
long int fib(int n);
long int fib2(int n);
int main(int argc, char * argv[])
{
  int nval, rept;
  struct timeval time1;
  struct timeval time2;
  float intv1, intv2;
  for (nval = 1; nval <= MAXN; nval ++)
    {
      long int fval;
      gettimeofday(& time1, NULL);
      for (rept = 0; rept < REPEAT; rept ++)
	{
	  fval = fib(nval);
	}
      gettimeofday(& time2, NULL);
      intv1 = (time2.tv_sec - time1.tv_sec) + 
	1e-6 * (time2.tv_usec - time1.tv_usec);
      printf("fib (%2d) = %ld, time = %f\n", 
	     nval, fval, intv1);
      gettimeofday(& time1, NULL);
      for (rept = 0; rept < REPEAT; rept ++)
	{
	  fval = fib2(nval);
	}
      gettimeofday(& time2, NULL);
      intv2 = (time2.tv_sec - time1.tv_sec) + 
	1e-6 * (time2.tv_usec - time1.tv_usec);
      printf("fib2(%2d) = %ld, time = %f\n", 
	     nval, fval, intv2);
      printf("ratio = %f\n", intv1/intv2);
    }
  return EXIT_SUCCESS;
}
