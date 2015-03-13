// subsetequal.c
#include <stdio.h>
int subsetEqual(int * setA, int sizeA, int kval, 
		unsigned int code)
{
  int sum = 0;
  int ind = 0;
  unsigned int origcode = code;
  while ((ind < sizeA) && (code > 0))
    {
      if ((code % 2) == 1)
	{
	  sum += setA[ind];
	}
      ind ++;
      code >>= 1;
    }
  if (sum == kval)
    {
      printf("equal: sum = %d, code = %X\n", 
	     sum, origcode);
      return 1;
    }
  return 0;
}
