// countstr.c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LINE_LENGTH 81
int main(int argc, char * argv[])
{
  if (argc < 4) // input word output
    {
      return EXIT_FAILURE;
    }
  // open the input file
  FILE * infptr;
  infptr = fopen(argv[1], "r");
  if (infptr == NULL)
    {
      return EXIT_FAILURE;
    }
  // open the output file
  FILE * outfptr;
  outfptr = fopen(argv[2], "w");
  if (outfptr == NULL)
    {
      fclose (infptr);
      return EXIT_FAILURE;
    }
  int count = 0;
  char oneline[LINE_LENGTH];
  while (fgets(oneline, LINE_LENGTH, infptr) != NULL)
    {
      if (strstr(oneline, argv[3]) != NULL)
	{
	  fprintf(outfptr, "%s", oneline);
	}
      char * chptr = oneline;
      while (chptr != NULL)
	{
	  chptr = strstr(chptr, argv[3]);
	  if (chptr != NULL)
	    {
	      count ++;
	      // if "eyeye" counts as two "eye"
	      chptr ++; 
	      // if "eyeye" counts as one "eye"
	      // chptr += strlen(argv[3]); 
	    }
	}
    }
  fprintf(outfptr, "%d\n", count);
  // close the input file
  fclose (infptr);
  // close outupt file
  fclose (outfptr);
  return EXIT_SUCCESS;
}
