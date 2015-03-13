// countint.c
#include <stdio.h>
int countInteger(FILE * fptr)
{
  int numInt = 0; // how many integers
  int value;
  while (fscanf(fptr, "%d", & value) == 1)
    {
      numInt ++;
    }
  return numInt;
}
