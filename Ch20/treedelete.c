// treedelete.c
#include "tree.h"
#include <stdlib.h>
TreeNode * Tree_delete(TreeNode * tn, int val)
{
  if (tn == NULL) { return NULL; }
  if (val < (tn -> value))
    {
      tn -> left = Tree_delete(tn -> left, val);
      return tn;
    }
  if (val > (tn -> value))
    {
      tn -> right = Tree_delete(tn -> right, val);
      return tn;
    }
  // v is the same as tn ->  value 
  if (((tn ->  left) == NULL) && ((tn ->  right) == NULL))
    {
      // tn has no child 
      free (tn);
      return NULL;
    }
  if ((tn ->  left) == NULL)
    {
      // tn ->  right must not be NULL 
      TreeNode * rc = tn ->  right;
      free (tn);
      return rc;
    }
  if ((tn ->  right) == NULL)
    {
      // tn ->  left must not be NULL 
      TreeNode * lc = tn ->  left;
      free (tn);
      return lc;
    }
  // tn have two children 
  // find the immediate successor 
  TreeNode * su = tn ->  right; // su must not be NULL 
  while ((su -> left) != NULL)
    {
      su = su -> left;
    }
  // su is tn's immediate successor 
  // swap their values 
  tn ->  value = su -> value;
  su -> value = val;
  // delete su 
  tn ->  right = Tree_delete(tn ->  right, val);
  return tn;  
}
