// countchar.c
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NUM_CHAR 26
int main(int argc, char * argv[])
{
  if (argc < 3) // need input and output
    {
      return EXIT_FAILURE;
    }
  // create an array of 26 integers
  char charcount[NUM_CHAR] = {0}; // initialize to zeros
  // without initialization, the elements are garbage 
  // open the input file
  FILE * infptr;
  infptr = fopen(argv[1], "r");
  if (infptr == NULL)
    {
      return EXIT_FAILURE;
    }
  // count the occurrences of the characters
  int onechar;
  do
    {
      onechar = fgetc(infptr);
      if (isupper(onechar))
	{
	  charcount[onechar - 'A'] ++;
	}
      if (islower(onechar))
	{
	  charcount[onechar - 'a'] ++;
	}
    }  while (onechar != EOF);
  // close the input file
  fclose (infptr);
  // open the output file
  FILE * outfptr;
  outfptr = fopen(argv[2], "w");
  if (outfptr == NULL)
    {
      return EXIT_FAILURE;
    }
  // write the array's elements to the file
  int ind;
  for (ind = 0; ind < NUM_CHAR; ind ++)
    {
      fprintf(outfptr, "%c: %d\n", ind  + 'A', charcount[ind]);
    }
  // close outupt file
  fclose (outfptr);
  return EXIT_SUCCESS;
}
