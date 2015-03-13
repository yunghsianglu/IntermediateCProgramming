#ifndef TREEITERATOR_H
#define TREEITERATOR_H
#include "tree.h"
#include "iteratorinternal.h"
typedef struct iteratornode2
{
  IteratorInternal * head;
  IteratorInternal * current;
  IteratorInternal * tail;
} TreeIterator;

TreeIterator * TreeIterator_construct(TreeNode * root);
int TreeIterator_hasNext(TreeIterator * iterator);
TreeNode * TreeIterator_visitNext(TreeIterator * iterator);
void TreeIterator_destroy(TreeIterator * iterator);
#endif
