/*
  coverage.c
  purpose: a condition that can never be true
*/
#include <stdio.h>
#include <stdlib.h>
int main(int argc, char * argv[])
{
  int x;
  int vx = 10;
  for (x = -100; x < 1000; x ++)
    {
      if ((x < 0) && (x > 400))
	{
	  vx = -vx;
	  printf("change direction\n");
	}
    }
  return EXIT_SUCCESS;
}
