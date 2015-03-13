// aredistinct.c
int areDistinct(int * arr, int len)
{
  int ind1;
  int ind2;
  for (ind1 = 0; ind1 < len; ind1 ++)
    {
      for (ind2 = ind1 + 1; ind2 < len; ind2 ++)
	{
	  if (arr[ind1] == arr[ind2])
	    {
	      // found two elements with the same value
	      return 0;
	    }
	}      
    }
  // have not found two elements of the same value
  return 1;
}
