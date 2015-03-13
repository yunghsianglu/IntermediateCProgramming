// list.c
#include "list.h"
#include "freq.h"
#include <stdlib.h>
ListNode * ListNode_create(TreeNode * tn)
{
  ListNode * ln = malloc(sizeof(ListNode));
  ln -> next = NULL;
  ln -> tnptr = tn;
  return ln;
}
// head may be NULL
// ln must not be NULL
// ln -> next must be NULL
ListNode * List_insert(ListNode * head, ListNode * ln, 
		       int mode)
{
  if (ln == NULL)
    {
      printf("ERROR! ln is NULL\n");
      return NULL;
    }
  if ((ln -> next) != NULL)
    {
      printf("ERROR! ln -> next is not NULL\n");
    }    
  if (head == NULL)
    {
      return ln;
    }
  if (mode == STACK)
    {
      ln -> next = head;
      return ln;
    }
  if (mode == QUEUE)
    {
      head -> next = List_insert(head -> next, ln, mode);
      return head;
    }
  // insert in increasing order
  int freq1 = (head -> tnptr) -> freq;
  int freq2 = (ln -> tnptr) -> freq;
  if (freq1 > freq2) 
    {
      // ln should be the first node
      ln -> next = head;
      return ln;
    }
  // ln should be after head
  head -> next = List_insert(head -> next, ln, mode);
  return head;
}
// frequencies must be sorted
ListNode * List_build(CharFreq * frequencies)
{
  // find the first index whose frequency is nonzero
  int ind = 0;
  while (frequencies[ind].freq == 0)
    {
      ind ++;
    }
  if (ind == NUMLETTER) 
    {
      // no letter appears
      return NULL;
    }
  // create a linked list, each node points to a tree node
  ListNode * head = NULL;
  while (ind < NUMLETTER)
    {
      TreeNode * tn = 
	TreeNode_create(frequencies[ind].value,
			frequencies[ind].freq);
      ListNode * ln = ListNode_create(tn);
      head = List_insert(head, ln, SORTED);
      ind ++;
    }
  return head;
}
void List_print(ListNode * head)
{
  if (head == NULL)
    {
      return;
    }
  Tree_print(head -> tnptr, 0);
  List_print(head -> next);
}
