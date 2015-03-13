// isvalid.c
#include <stdio.h>
int isValidSet(int * setA, int sizeA)
// valid if every element is positive and distinct
// return 1 if valid, 0 if invalid
{
  int ind1, ind2;
  for (ind1 = 0; ind1 < sizeA; ind1 ++)
    {
      if (setA[ind1] <= 0)
	{ 
	  return 0;
	}
      for (ind2 = ind1 + 1; ind2 < sizeA; ind2 ++)
	{
	  if (setA[ind1] == setA[ind2])
	    { 
	      return 0;
	    }
	}
    }
  return 1;
}

