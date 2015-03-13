// freq.c
#include "constant.h"
#include "freq.h"
#include <stdio.h>
#include <stdlib.h>
#include <strings.h>
int countFrequency(char * filename, CharFreq * freq)
{
  FILE * fptr = fopen(filename, "r");
  int count = 0;
  if (fptr == NULL)
    {
      return 0;
    }
  while (! feof (fptr))
    {
      int onechar = fgetc(fptr);
      if (onechar != EOF)
	{
	  count ++;
	  freq[onechar].value = (char) onechar;
	  freq[onechar].freq ++;
	}
    }
  fclose (fptr);
  return count;
}
void printFrequency(CharFreq * freq)
{
  int ind;
  for (ind = 0; ind < NUMLETTER; ind ++)
    {
      printf("%d %d\n", freq[ind].value, 
	     freq[ind].freq);
    }
  printf("------------------------\n");
}
static int compareFreq(const void * p1, const void * p2)
{
  const CharFreq * ip1 = (const CharFreq *) p1;
  const CharFreq * ip2 = (const CharFreq *) p2;
  const int iv1 = ip1 -> freq;
  const int iv2 = ip2 -> freq;
  return (iv1 - iv2);
}
void sortFrequency(CharFreq * freq)
{
  qsort(freq, NUMLETTER, sizeof(CharFreq), compareFreq);
}
