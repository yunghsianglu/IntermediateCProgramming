// treeinsert.c
#include "tree.h"
#include <stdlib.h>
static TreeNode * TreeNode_construct(int val)
{
  TreeNode * tn;
  tn = malloc(sizeof(TreeNode));
  tn -> left = NULL;
  tn -> right = NULL;
  tn -> value = val;
  return tn;
}

TreeNode * Tree_insert(TreeNode * tn, int val)
{
  if (tn == NULL)
    {
      // empty, create a node
      return TreeNode_construct(val);
    }
  // not empty
  if (val == (tn -> value))
    {
      // do not insert the same value
      return tn;
    }
  if (val < (tn -> value))
    {
      tn -> left = Tree_insert(tn -> left, val);
    }
  else
    {
      tn -> right = Tree_insert(tn -> right, val);
    }
  return tn;
}
