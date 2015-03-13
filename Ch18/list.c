/*
  file: list.c
*/
#include "list.h"
#include <stdio.h>
#include <stdlib.h>
static Node * Node_construct(int v)
/*
  A static function can be called by functions only in 
  this file. Functions outside this file cannot call it.
 */
{
  Node * n = malloc(sizeof(Node));
  n -> value = v;
  n -> next = NULL;
  return n;
}

Node * List_insert(Node * head, int v)
{
  printf("insert %d\n", v);
  Node * p = Node_construct(v); 
  p -> next = head;
  return p;   /* insert at the beginning */
}

Node * List_search(Node * head, int v)
{
  Node * p = head;
  while (p != NULL)
    {
      if ((p -> value) == v)
	{
	  return p;
	}
      p = p -> next;
    }
  return p;
}

Node * List_delete(Node * head, int v)
{
  printf("delete %d\n", v);
  Node * p = head;
  if (p == NULL) /* empty list, do nothing */
    {
      return p;
    }
  /* delete the first node (i.e. head node)? */
  if ((p -> value) == v)
    {
      p = p -> next;
      free (head);
      return p;
    }

  /* not deleting the first node */

  Node * q = p -> next;
  while ((q != NULL) && ((q -> value) != v))
    {
      /* must check whether q is NULL 
	 before checking q -> value */
      p = p -> next;
      q = q -> next;
    }
  if (q != NULL) 
    { 
      /* find a node whose value is v */
      p -> next = q -> next;
      free (q);
    }
  return head; 
}

void List_destroy(Node * head)
{
  while (head != NULL)
    {
      Node * p = head -> next;
      free (head);
      head = p;
    }
}

void List_print(Node * head)
{
  printf("\nPrint the whole list:\n");
  while (head != NULL)
    {
      printf("%d ", head -> value);
      head = head -> next;
    }
  printf("\n\n");
}
