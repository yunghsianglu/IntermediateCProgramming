// sequential.c
#include "subsetsum.h"
int subsetSum(int * setA, int sizeA, int kval)
{
  unsigned int maxCode = 1;
  unsigned int ind;
  for (ind = 0; ind < sizeA; ind ++)
    {
      maxCode *= 2;
    }
  int total = 0;
  for (ind = 1; ind < maxCode; ind ++)
    {
      total += subsetEqual(setA, sizeA, kval, ind);
    }
  return total;
}

