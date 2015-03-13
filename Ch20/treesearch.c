// treesearch.c
#include "tree.h"
TreeNode * Tree_search(TreeNode * tn, int val)
{
  if (tn == NULL) 
    {
      // cannot find 
      return NULL;
    }
  if (val == (tn -> value))
    {
      // found 
      return tn;
    }
  if (val < (tn -> value))
    {
      // search the left side 
      return Tree_search(tn -> left, val);
    }
  return Tree_search(tn -> right, val);
}

