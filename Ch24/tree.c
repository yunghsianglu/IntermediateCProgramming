// tree.c
#include "tree.h"
#include "utility.h"
#include <stdio.h>
#include <stdlib.h>
TreeNode * TreeNode_create(char val, int freq)
{
  TreeNode * tn = malloc(sizeof(TreeNode));
  tn -> left = NULL;
  tn -> right = NULL;
  tn -> value = val;
  tn -> freq = freq;
  return tn;
}
TreeNode * Tree_merge(TreeNode * tn1, TreeNode * tn2)
{
  TreeNode * tn = malloc(sizeof(TreeNode));
  tn -> left = tn1;
  tn -> right = tn2;
  tn -> value = 0; // do not care
  tn -> freq = tn1 -> freq + tn2 -> freq;
  return tn;
}
// post-order
void Tree_print(TreeNode * tn, int level)
{
  if (tn == NULL)
    {
      return;
    }
  TreeNode * lc = tn -> left;  // left child
  TreeNode * rc = tn -> right; // right child
  Tree_print(lc, level + 1);
  Tree_print(rc, level + 1);
  int depth;
  for (depth = 0; depth < level; depth ++)
    {
      printf("    ");
    }
  printf("freq = %d ", tn -> freq);
  if ((lc == NULL) && (rc == NULL))
    {
      // a leaf node
      printf("value = %d, '%c'", tn -> value, tn -> value);
    }
  printf("\n");
}
static int Tree_heightHelper(TreeNode * tn, int height)
{
  if (tn == 0)
    {
      return height;
    }
  int lh = Tree_heightHelper(tn -> left, height + 1);
  int rh = Tree_heightHelper(tn -> right, height + 1);
  if (lh < rh)
    { 
      return rh;
    }
  if (lh > rh)
    { 
      return lh;
    }
  return lh;
}
int Tree_height(TreeNode * tn)
{
  return Tree_heightHelper(tn, 0);
}
static void Tree_leafHelper(TreeNode * tn, int * num)
{
  if (tn == 0)
    {
      return;
    }
  // if it is a leaf node, add one
  TreeNode * lc = tn -> left;
  TreeNode * rc = tn -> right;
  if ((lc == NULL) && (rc == NULL))
    {
      (* num) ++;
      return;
    }
  Tree_leafHelper(lc, num);
  Tree_leafHelper(rc, num);
}
int Tree_leaf(TreeNode * tn)
{
  int num = 0;
  Tree_leafHelper(tn, & num);
  return num;
}
// print the 7 bits of an ASCII character
static void char2bits(FILE * outfptr, int ch, 
		      unsigned char * whichbit,
		      unsigned char * curbyte)
{
  unsigned char mask = 0x40; // only 7 bits
  while (mask > 0)
    {
      writeBit(outfptr, (ch & mask) == mask,
	       whichbit, curbyte);
      mask >>= 1;
    }
}
static void Tree_headerHelper(TreeNode * tn, 
			      FILE * outfptr,
			      unsigned char * whichbit,
			      unsigned char * curbyte)
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
      writeBit(outfptr, 1, whichbit, curbyte);
      char2bits(outfptr, tn -> value, whichbit, curbyte);
      return;
    }
  Tree_headerHelper(lc, outfptr, whichbit, curbyte);
  Tree_headerHelper(rc, outfptr, whichbit, curbyte);
  writeBit(outfptr, 0, whichbit, curbyte);
}
void Tree_header(TreeNode * tn, unsigned int numChar, 
		 char * outfile)
{
  FILE * outfptr = fopen(outfile, "w");
  if (outfptr == NULL)
    {
      return;
    }
  unsigned char whichbit = 0;
  unsigned char curbyte = 0;
  Tree_headerHelper(tn, outfptr, & whichbit, & curbyte);
  // add one more 0 to end the header
  writeBit(outfptr, 0, & whichbit, & curbyte);
  padZero(outfptr, & whichbit, & curbyte);
  // write the number of characters
  fwrite(& numChar, sizeof(unsigned int), 1, outfptr);
  // add '\n' at the end of the header
  unsigned char newline = '\n';
  fwrite(& newline, sizeof(unsigned char), 1, outfptr);
  fclose (outfptr);
}
void Tree_destroy(TreeNode * tn)
{
  if (tn == NULL)
    {
      return;
    }
  Tree_destroy(tn -> left);
  Tree_destroy(tn -> right);
  free (tn);
}
