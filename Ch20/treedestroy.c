// treedestroy.c
#include "tree.h"
#include <stdlib.h>
void Tree_destroy(TreeNode * n)
{
  if (n == NULL) 
    {
      return;
    }
  Tree_destroy(n -> left);
  Tree_destroy(n -> right);
  free(n);
}

