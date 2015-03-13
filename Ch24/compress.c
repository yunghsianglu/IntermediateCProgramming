// compress.c
#include <stdio.h>
#include "tree.h"
#include "constant.h"
static void Tree_headerHelper(TreeNode * tn, FILE * outfptr)
{
  if (tn == NULL)
    {
      return; // should not get here
    }
  TreeNode * lc = tn -> left;
  TreeNode * rc = tn -> right;
  if ((lc == NULL) && (rc == NULL))
    {
      // leaf node
      fprintf(outfptr, "1%c", tn -> value);
      return;
    }
  Tree_headerHelper(lc, outfptr);
  Tree_headerHelper(rc, outfptr);
  fprintf(outfptr, "0");
}
void Tree_header(TreeNode * tn, char * outfile)
{
  FILE * outfptr = fopen(outfile, "w");
  if (outfptr == NULL)
    {
      return;
    }
  Tree_headerHelper(tn, outfptr);
  fprintf(outfptr, "0\n");
  fclose (outfptr);
}
int compress(char * infile, char * outfile, 
	     int * * codebook, int * mapping)
{
  FILE * infptr = fopen(infile, "r");
  if (infptr == NULL)
    {
      return 0;
    }
  FILE * outfptr = fopen(outfile, "a"); // append
  if (outfptr == NULL)
    {
      fclose (outfptr);
      return 0;
    }
  while (! feof(infptr))
    {
      int onechar = fgetc(infptr);
      if (onechar != EOF)
	{
	  int ind = mapping[onechar];
	  int ind2 = 1;
	  while (codebook[ind][ind2] != -1)
	    {
	      fprintf(outfptr, "%d", codebook[ind][ind2]);
	      ind2 ++;
	    }
	}
    }
  fclose(infptr);
  fclose(outfptr);
  return 1;
}
// ********************************************
  // continue encode ...
  Tree_header(root, outfile);
  // mapping from ASCII to the indexes of the code book
  int mapping[NUMLETTER];
  int ind;
  for (ind = 0; ind < NUMLETTER; ind ++)
    {
      mapping[ind] = -1; // initialized to invalid index
      int ind2;
      for (ind2 = 0; ind2 < numRow; ind2 ++)
	{
	  if (codebook[ind2][0] == ind)
	    {
	      mapping[ind] = ind2;
	    }
	}
    }
   compress(infile, outfile, codebook, mapping);
