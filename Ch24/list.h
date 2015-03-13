// list.h
#ifndef LIST_H
#define LIST_H
#include "tree.h"
#include "constant.h"
#include "freq.h"
#include <stdio.h>
#define QUEUE  0
#define STACK  1
#define SORTED 2
typedef struct listnode
{
  struct listnode * next;
  TreeNode * tnptr;
} ListNode;
ListNode * List_build(CharFreq * frequencies);
ListNode * ListNode_create(TreeNode * tn);
// The mode is QUEUE, STACK, or SORTED
ListNode * List_insert(ListNode * head, ListNode * ln, int mode);
void List_print(ListNode * head);
#endif
