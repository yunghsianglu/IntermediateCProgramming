#include <stdio.h>
#include <stdlib.h>
#define EGSIZE 8
int main(int argc, char ** argv)
{
  char value[EGSIZE] = 
    {'E', 'N', 'G', 'T', 'g', 'p', 'd', 'h'};
  int freq[EGSIZE] = { 1, 2, 7, 7, 19, 23, 46, 73};
  int ind1;
  int ind2;
  for (ind1 = 0; ind1 < EGSIZE; ind1 ++)
    {
      for (ind2 = 0; ind2 < freq[ind1]; ind2 ++)
	{
	  printf("%c", value[ind1]);
	}
    }
  return EXIT_SUCCESS;
}
