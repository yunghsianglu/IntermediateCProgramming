#include "tree.h"
#include "treeiterator.h"
#include <stdlib.h>
#include <stdio.h>
static IteratorInternal * IteratorInternal_construct(TreeNode * p)
{
  IteratorInternal * internal = malloc(sizeof(IteratorInternal));
  internal -> treenode = p;
  internal -> next = NULL;
  return internal;
}

TreeIterator * TreeIterator_construct(TreeNode * p)
{
  TreeIterator * iter = malloc(sizeof(TreeIterator));
  IteratorInternal * internal = IteratorInternal_construct(p);
  iter -> head = internal;
  iter -> current = internal;
  iter -> tail = internal;
  return iter;
}

int TreeIterator_hasNext(TreeIterator * iter)
{
  return ((iter -> current) != NULL);
}

static void TreeIterator_insert(TreeIterator * iter)
{
  TreeNode * tailnode = (iter -> tail) -> treenode;
  if ((tailnode -> left) != NULL)
    {
      IteratorInternal * internal = 
	IteratorInternal_construct(tailnode -> left);
      (iter -> tail) -> next = internal;
      iter -> tail = internal;
    }

  if ((tailnode -> right) != NULL)
    {
      IteratorInternal * internal = 
	IteratorInternal_construct(tailnode -> right);
      (iter -> tail) -> next = internal;
      iter -> tail = internal;
    }
}

TreeNode * TreeIterator_visitNext(TreeIterator * iter)
{
  if (TreeIterator_hasNext(iter) == 0)
    {
      return NULL;
    }
  TreeNode * treenode = (iter -> current) -> treenode;
  TreeIterator_insert(iter);
  iter -> current = (iter -> current) -> next;
  return treenode;
}

void TreeIterator_destroy(TreeIterator * iterator)
{
  IteratorInternal * internal = iterator -> head;
  while (internal != NULL)
    {
      IteratorInternal * curr = internal;
      internal = internal -> next;
      free (curr);
    }
  free (iterator);
}

void visitTree(TreeNode * root)
{
  printf("----------Iterator-------------");
  TreeIterator * iterator = TreeIterator_construct(root);
  while (TreeIterator_hasNext(iterator))
    {
      TreeNode * n = TreeIterator_visitNext(iterator);
      TreeNode_print(n);
    }
  printf("\n\n");
  TreeIterator_destroy(iterator);
}
